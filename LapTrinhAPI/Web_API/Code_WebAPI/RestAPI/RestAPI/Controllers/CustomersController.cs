using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace RestAPI.Controllers
{
    public class CustomersController : ApiController
    {
        //httpGet: dùng để lấy thông tin khách hàng
        //1. Dịch vụ lấy thông tin của toàn bộ khách hàng
        [HttpGet]
        public List<KHACHHANG> GetKHACHHANGs()
        {
            DBCustomerDataContext dbCustomer = new DBCustomerDataContext();
            return dbCustomer.KHACHHANGs.ToList();
        }
        //2. Dịch vụ lấy thông tin một khách hàng với mã nào đó
         [HttpGet]
        public KHACHHANG GetCustomer(string id)
        {
            DBCustomerDataContext dbCustomer = new DBCustomerDataContext();
            return dbCustomer.KHACHHANGs.FirstOrDefault(x =>
           x.MaKH == id);
        }
        //3. httpPost, dịch vụ thêm mới một khách hàng
        [HttpPost]
        public bool InsertNewCustomer(string id, string name,
       string adress, string phoneNumber)
        {
            try
            {
                DBCustomerDataContext dbCustomer = new DBCustomerDataContext();
                KHACHHANG customer = new KHACHHANG();
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = adress;
                customer.SDT = phoneNumber;

                dbCustomer.KHACHHANGs.InsertOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        //4. httpPut để chỉnh sửa thông tin một khách hàng
        [HttpPut]
        public bool UpdateCustomer(string id, string name,
       string adress, string phoneNumber)
        {
            try
            {
                DBCustomerDataContext dbCustomer = new DBCustomerDataContext();
                //Lấy mã khách đã có
                KHACHHANG customer =
               dbCustomer.KHACHHANGs.FirstOrDefault(x => x.MaKH == id);
                if (customer == null) return false;
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = adress;
                customer.SDT= phoneNumber;
                dbCustomer.SubmitChanges();//Xác nhận chỉnh sửa
            return true;
            }
            catch
            {
                return false;
            }
        }
        //5.httpDelete để xóa một Khách hàng
        [HttpDelete]
        public bool DeleteCustomer(string id)
        {
            try
            {
                DBCustomerDataContext dbCustomer = new DBCustomerDataContext();
                //Lấy mã khách đã có
                KHACHHANG customer = dbCustomer.KHACHHANGs.FirstOrDefault(x => x.MaKH == id);
                if (customer == null) return false;

                dbCustomer.KHACHHANGs.DeleteOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
