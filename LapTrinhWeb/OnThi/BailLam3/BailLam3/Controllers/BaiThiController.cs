
using BailLam3.Models.Entity;
using PagedList;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BailLam3.Controllers
{
    public class BaiThiController : Controller
    {
        db_baithi db = new db_baithi();
        // GET: BaiThi
        public ActionResult Index()
        {
            return View();
        }
         
        public ActionResult RenderNav()
        {
            List<Categories> list = db.Categories.ToList();
            return PartialView("NguyenThiNgu_Header", list);
        }

        public ActionResult RenderProduct(int? page)
        {
            int PageSize = 4;
            int PageNumber = (page ?? 1);
            List<Products> list = db.Products.Where(x => x.UnitPrice > 100 && x.Available == true).ToList();
            return PartialView("NguyenThiNgu_MainContent", list.ToPagedList(PageNumber, PageSize));
        }

        public ActionResult RenderByCata(int Id)
        {
            List<Products> list = db.Products.Where(x => x.CategoryId == Id && x.Available == true).ToList();
            return PartialView("ProductByCata", list);
        }

        public ActionResult SearchProduct(string Value)
        {
            List<Products> list = db.Products.Where(x => x.Name.Contains(Value) && x.Available == true).ToList();
            return PartialView("ProductByCata", list);
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

        [HttpGet]
        public ActionResult Detail(string id)
        {
            var sp = db.Products.Where(n => n.Id == id).FirstOrDefault();
            return View(sp);

        }

        [HttpGet]
        public ActionResult Delete(string id)
        {
            var sp = db.Products.Where(n => n.Id == id).FirstOrDefault();
            if (sp == null)
            {
                Response.StatusCode = 404;
                return null;
            }
            return View(sp);
        }
        [HttpPost, ActionName("Delete")]
        public ActionResult CFDelete(string  id)
        {
            Products sp = db.Products.Where(n => n.Id == id).FirstOrDefault();
            if (sp == null)
            {

                Response.StatusCode = 404;
                return null;
            }
            db.Products.Remove(sp);
            db.SaveChanges();
            return RedirectToAction("Index", "BaiThi/Index");
        }
    }
}