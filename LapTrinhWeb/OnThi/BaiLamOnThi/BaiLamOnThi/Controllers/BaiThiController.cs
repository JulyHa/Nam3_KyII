using BaiLamOnThi.Models.Entity;
using PagedList;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BaiLamOnThi.Controllers
{
    public class BaiThiController : Controller
    {
        Database db = new Database();
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
            int pageSize = 4;
            int pageNumber = (page ?? 1);
            //List<Products> list = db.Products.Where(x => x.UnitPrice >= 100 && x.Available == true).Take(4).ToList();
            List<Products> list = db.Products.Where(x => x.UnitPrice >= 100 && x.Available == true).ToList();
            return View("RenderProduct", list.ToPagedList(pageNumber, pageSize));
            
        }

        public ActionResult RenderCata(int Id)
        {
            List<Products> list = db.Products.Where(x => x.CategoryId == Id && x.Available == true).ToList();
            return PartialView("NguyenThiNgu_MainContent", list);
        }

        public ActionResult SearchProduct(String input)
        {
            if(input.Length == 0)
            {
                List<Products> list = db.Products.Where(x => x.Available == true).ToList();
                return PartialView("NguyenThiNgu_MainContent", list);
            }
            List<Products> p = db.Products.Where(x => x.Name.Contains(input)).ToList();
            return PartialView("NguyenThiNgu_MainContent", p);
        }

        public ActionResult Create()
        {
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
            return View();
        }

        [HttpPost]
        public ActionResult Create(Products products)
        {
            ViewBag.Err = "";
            if (ModelState.IsValid)
            {
                List<Products> l = db.Products.Where(x => x.Id == products.Id).ToList();
                if(l.Count() > 0)
                {
                    ViewBag.Err = "ID đã tồn tại";
                    ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
                    return View();
                }
                db.Products.Add(products);
                db.SaveChanges();
                return Redirect("Index");
            }
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "NameVN");
            return View();
        }

        public ActionResult CreateSignUp()
        {
            return View();
        }

        [HttpPost]
        public ActionResult CreateSignUp(Customers customer)
        {
            ViewBag.Err = "";
            if (ModelState.IsValid)
            {
                List<Customers> list = db.Customers.Where(x => x.Id == customer.Id).ToList();
                if(list.Count > 0)
                {
                    ViewBag.Err = "ID đã tồn tại";
                    return View();
                }
                db.Customers.Add(customer);
                db.SaveChanges();
                return Redirect("Index");

            }
            return View();
        }

    }
}