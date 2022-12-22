using BaiLam4.Models.Entity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BaiLam4.Controllers
{
    public class BaiThiController : Controller
    {
        // GET: BaiThi

        Data db = new Data();
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult RenderNav()
        {
            Cata_Product sp = new Cata_Product();

            List<Categories> cata = db.Categories.ToList();
            List<Products> pro = db.Products.Where(x => x.Available == true && x.UnitPrice < 1000).ToList();
            sp.category = cata;
            sp.product = pro;

            return PartialView("NguyenThiNgu_MainContent", sp);
        }

        public ActionResult RenderbyCata(int Id)
        {
            Cata_Product sp = new Cata_Product();

            List<Categories> cata = db.Categories.ToList();
            List<Products> pro = db.Products.Where(x => x.Available == true && x.UnitPrice < 1000 && x.CategoryId == Id).ToList();
            sp.category = cata;
            sp.product = pro;

            return PartialView("NguyenThiNgu_MainContent", sp);

        }
        public ActionResult Create()
        {
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
            return View();
        }

        [HttpPost]
        public ActionResult Create(Products products)
        {
            if (ModelState.IsValid)
            {
                db.Products.Add(products);
                db.SaveChanges();
                return Redirect("Index");
            }
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
            return View();
        }

    }
}