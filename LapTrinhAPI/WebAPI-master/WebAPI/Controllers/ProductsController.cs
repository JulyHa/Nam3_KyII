using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace WebAPI.Controllers
{
    public class ProductsController : ApiController
    {
        [HttpGet]
        public List<tblSanPham> GetSanPhams()
        {
            DBCustomersDataContext db = new DBCustomersDataContext();
            return db.tblSanPhams.ToList();
        }
        [HttpGet]
        public tblSanPham GetProduct(string id)
        {
            DBCustomersDataContext db = new DBCustomersDataContext();
            return db.tblSanPhams.FirstOrDefault(n => n.MaSP == id);
        }
        [Route("Search/{name}")]
        [HttpGet]
        public List<tblSanPham> GetSanPham(string name)
        {
            DBCustomersDataContext db = new DBCustomersDataContext();
            return db.tblSanPhams.Where(n => n.TenSP.Contains(name)).ToList();
        }
        [Route("TonKho")]
        [HttpGet]
        public List<tblSanPham> GetTonKho()
        {
            DBCustomersDataContext db = new DBCustomersDataContext();
            return db.tblSanPhams.Where(n => n.SoLuong > 0).ToList();
        }
        [HttpPost]
        public bool InsertNewProduct(string id, string name, string description, decimal PriceIn, decimal PriceOut, int number)
        {
            try
            {
                DBCustomersDataContext dBProduct = new DBCustomersDataContext();
                tblSanPham product = new tblSanPham();
                product.MaSP = id;
                product.TenSP = name;
                product.MoTa = description;
                product.GiaNhap = PriceIn;
                product.GiaBan = PriceOut;
                product.SoLuong = number;
                dBProduct.tblSanPhams.InsertOnSubmit(product);
                dBProduct.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        [HttpPut]
        public bool UpdateCustomer(string id, string name, string description, decimal PriceIn, decimal PriceOut, int number)
        {
            try
            {
                DBCustomersDataContext dBProduct = new DBCustomersDataContext();
                tblSanPham product = dBProduct.tblSanPhams.FirstOrDefault(n=>n.MaSP == id);
                if(product == null) { return false; }
                product.MaSP = id;
                product.TenSP = name;
                product.MoTa = description;
                product.GiaNhap = PriceIn;
                product.GiaBan = PriceOut;
                product.SoLuong = number;
                dBProduct.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        [HttpDelete]
        public bool DeleteCustomers(string id)
        {
            try
            {
                DBCustomersDataContext dBProduct = new DBCustomersDataContext();
                tblSanPham product = dBProduct.tblSanPhams.FirstOrDefault(n => n.MaSP == id);
                if (product == null) { return false; }
                dBProduct.tblSanPhams.DeleteOnSubmit(product);
                dBProduct.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
