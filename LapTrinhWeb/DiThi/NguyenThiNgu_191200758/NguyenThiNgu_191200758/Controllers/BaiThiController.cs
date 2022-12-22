using NguyenThiNgu_191200758.Models.Entity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace NguyenThiNgu_191200758.Controllers
{
   
    public class BaiThiController : Controller
    {
        Database_BaiThi data = new Database_BaiThi();
        // GET: BaiThi
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult RenderNav()
        {
            List<NavItems> list = data.NavItems.ToList();
            return PartialView("NguyenThiNgu_Nav", list);
        }

        public ActionResult RenderProduct()
        {
            List<Products> l = data.Products.Where(x => x.Available == true).OrderBy(x => x.UnitPrice).Take(4).ToList();
            return PartialView("NguyenThiNgu_MainContent", l);
        }

        public ActionResult RenderbyCata(string Value)
        {
            List<Products> l = data.Products.Where(x => x.Available == true && x.Name.Contains(Value)).ToList();
            return PartialView("NguyenThiNgu_MainContent", l);
        }

        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Create(Customers customer)
        {
            if (ModelState.IsValid)
            {
                data.Customers.Add(customer);
                data.SaveChanges();
                return Redirect("Index");
            }
            return View();
        }
    }
}