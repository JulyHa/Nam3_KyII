using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using OnThiWeb1.Models;

namespace OnThiWeb1.Controllers
{
    
    public class MainController : Controller
    {
        OnlineShopEntities1 db = new OnlineShopEntities1();
        // GET: Main
        public ActionResult Index()
        {
            return View();
        }
        public ActionResult Loaddropdownlist()
        {
            List<Category> list = db.Categories.ToList();
            return PartialView("ThanhTran_Filter", list);
        }
        public ActionResult Loadproduct()
        {
            /*List<Product> list = db.Products.Where(a => a.Available == true).ToList();
            return PartialView("ThanhTran_MainContent", list);*/

            var list = (from t in db.Products
                        where t.Available == true 
                        orderby t.UnitPrice descending
                        select t).Take(3).ToList();
            return PartialView("ThanhTran_MainContent", list);
        }
        [HttpGet]
        public ActionResult AddCustomers()
        {
           // ViewBag.MaSP = new SelectList(db.tSanPhams.OrderBy(n => n.MaSP), "MaSP", "TenSP");
            return View();
        }
        [HttpPost]//đẩy dữ liệu và sever
        [ValidateAntiForgeryToken]
        public ActionResult AddCustomers(Customer cus)
        {
            if (ModelState.IsValid)
            {
                db.Customers.Add(cus);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(cus);
        }
       

        public ActionResult EvenDropdownlist(int Idd)
        {
           
                List<Product> list = db.Products.Where(a => a.CategoryId == Idd).ToList();
                if (Idd == 0)
                {
                    List<Product> list1 = db.Products.Where(a => a.Available == true).ToList();
                    return PartialView("ThanhTran_MainContent", list1);
                }
                return PartialView("ThanhTran_MainContent", list);
           
        }
        
        public ActionResult KetQuaTimKiem(string searchString)
        {
            List<Product> list = db.Products.Where(c => c.Name.Contains(searchString)).ToList();
            return PartialView("ThanhTran_MainContent",list);
        }
        /* [HttpPost]
         public ActionResult KetQuaTimKiem(FormCollection f)
         {
             string search = f["txtTimKiem"].ToString();
             List<Product> lstspTK = db.Products.Where(n => n.Name.Contains(search)).ToList();

             if (lstspTK.Count == 0)
             {
                 ViewBag.ThongBao = "Không có sản phẩm của bạn muốn tìm kiếm";
             }
             ViewBag.ThongBao = "Đã tìm thấy sản phẩm" + search + "kết quả:";
             return View("ThanhTran_MainContent",lstspTK);
         }
         [HttpGet]
         public ActionResult KetQuaTimKiem(string searchString)
         {
             ViewBag.keyword = search;
             List<Product> lstspTK = db.Products.Where(n => n.Name.Contains(search)).ToList();


             if (lstspTK.Count == 0)
             {
                 ViewBag.ThongBao = "Không có sản phẩm của bạn muốn tìm kiếm";
                 //return View(db.tSanPhams.OrderBy(n => n.TenSP).ToPagedList(pageNumber, pageSize));
             }
             ViewBag.ThongBao = "Đã tìm thấy sản phẩm" + search + "kết quả:";
             return View("ThanhTran_MainContent", lstspTK);
         }*/
       
        
    }
}