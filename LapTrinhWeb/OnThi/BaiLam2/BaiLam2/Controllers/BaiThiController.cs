
using BaiLam2.Models.Entity;
using PagedList;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BaiLam2.Controllers
{
    public class BaiThiController : Controller
    {
        // GET: BaiThi
        database_Ngu db = new database_Ngu();
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult RenderNav()
        {
            List<Categories> list = db.Categories.ToList();
            return PartialView("NguyenThiNgu_Header", list);
        }
        public ActionResult RenderMain(int? page)
        {
            int PageSize = 4;
            int PageNumber = (page ?? 1);
            List<Products> list = db.Products.Where(x => x.Available == true && x.UnitPrice > 400).ToList();
            return PartialView("RenderMain", list.ToPagedList(PageNumber, PageSize));
        }
        public ActionResult RenderProduct()
        {
            List<Products> list = db.Products.Where(x => x.Available == true && x.UnitPrice > 400).ToList();
            return PartialView("NguyenThiNgu_MainContent", list);
        }
        public ActionResult RenderCata(int Id)
        {
            List<Products> list = db.Products.Where(x => x.CategoryId == Id && x.Available == true).ToList();
            return PartialView("NguyenThiNgu_MainContent", list);
        }

        public ActionResult SearchProduct(String value)
        {
            List<Products> list = db.Products.Where(x => x.Name.Contains(value) && x.Available == true).ToList();
            return PartialView("NguyenThiNgu_MainContent", list);
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

        public ActionResult Delete()
        {
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
            return View();
        }
        [HttpDelete]
        public ActionResult Delete(Products products)
        {

            db.Products.Remove(products);
            db.SaveChanges();
            return Redirect("Index");
        }
    }
}