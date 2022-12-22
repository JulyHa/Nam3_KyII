using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using OnThiWeb12.Models;

namespace OnThiWeb12.Controllers
{
    public class ThanhTranController : Controller
    {
        OnlineShopEntities db = new OnlineShopEntities();
        // GET: ThanhTran
        public ActionResult Index()
        {
            return View();
        }
        public ActionResult LoadMenu()
        {
            List<Category> list = db.Categories.ToList();
            return PartialView("TranTatThanh_MainContent", list);
        }
        public ActionResult LoadProduct()
        {
            List<Product> list = db.Products.Where(a=>a.Available== true && a.UnitPrice <= 1000).ToList();
            return PartialView("TranTatThanh_RightProducts", list);
        }
// Câu 4 
        public ActionResult PhanLoaiTheoSanPham(int MaSP)
        {
            List<Product> list = db.Products.Where(a=>a.CategoryId == MaSP ).ToList();
            return PartialView("TranTatThanh_RightProducts", list);
        }
    }
}