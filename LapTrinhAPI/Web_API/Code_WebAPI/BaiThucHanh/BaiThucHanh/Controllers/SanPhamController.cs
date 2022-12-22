using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace BaiThucHanh.Controllers
{
    public class SanPhamController : ApiController
    {
        //Get ds sản phẩm
        [HttpGet]
        //Get ds sản phẩm theo ten
        public List<tblSanPham> GetSanPhams_Ten(string name)
        {
            DBContextDataContext db = new DBContextDataContext();
            return db.tblSanPhams.Where(x => x.TenSP == name).ToList();
        }

        //Get ds sản phẩm tồn kho(sl > 0)
        [HttpGet]
        public List<tblSanPham> GetSanPhams_TonKho()
        {
            DBContextDataContext db = new DBContextDataContext();
            return db.tblSanPhams.Where(x => x.SoLuong > 0).ToList();
        }

        //Post 1 sản phẩm
        [HttpPost]
        public bool InsertNewCustomer(string id, string name,string mota, int nhap, int xuat, int sl)
        {
            try
            {
                DBContextDataContext db = new DBContextDataContext();
                tblSanPham sanPham = new tblSanPham();
                sanPham.MaSP = id;
                sanPham.TenSP = name;
                sanPham.MoTa = mota;
                sanPham.GiaNhap = nhap;
                sanPham.GiaBan = xuat;
                sanPham.SoLuong = sl;

                db.tblSanPhams.InsertOnSubmit(sanPham);
                db.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }

        //4. Put để sửa thông tin 1 sản phẩm
        [HttpPut]
        public bool UpdateCustomer(string id, string name, string mota, int nhap, int xuat, int sl)
        {
            try
            {
                DBContextDataContext db = new DBContextDataContext();
                //Lấy mã sp đã có
                tblSanPham sanPham = db.tblSanPhams.FirstOrDefault(x => x.MaSP == id);
                if (sanPham == null) return false;
                sanPham.TenSP = name;
                sanPham.MoTa = mota;
                sanPham.GiaNhap = nhap;
                sanPham.GiaBan = xuat;
                sanPham.SoLuong = sl;
                db.SubmitChanges();//Xác nhận chỉnh sửa
                return true;
            }
            catch
            {
                return false;
            }
        }
        //5.Delete 1 sản phẩm
        [HttpDelete]
        public bool DeleteCustomer(string id)
        {
            try
            {
                DBContextDataContext db = new DBContextDataContext();
                //Lấy mã khách đã có
                tblSanPham sanPham = db.tblSanPhams.FirstOrDefault(x => x.MaSP == id);
                if (sanPham == null) return false;

                db.tblSanPhams.DeleteOnSubmit(sanPham);
                db.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
