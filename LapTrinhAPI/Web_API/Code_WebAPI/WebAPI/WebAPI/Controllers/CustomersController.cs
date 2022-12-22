using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Http.Cors;

namespace WebAPI.Controllers
{
    [EnableCors(origins: "https://localhost:44310", headers: "*", methods: "")]
    public class CustomersController : ApiController
    {
        //1. Dich vu lay thong tin khach hang
        [HttpGet]
        public List<KHACHHANG> GetKHACHHANGs()
        {
            DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
            return dbCustomer.KHACHHANGs.ToList();
        }
        //2. Dich vu thong tin mot khach hang voi ma nao do
        [HttpGet]
        public KHACHHANG GetCustomers(string id)
        {
            DBCustomersDataContext dBCustomers = new DBCustomersDataContext();
            return dBCustomers.KHACHHANGs.FirstOrDefault(x => x.MaKH == id);
        }
        //3. Dich vu them moi mot khach hang
        [HttpPost]
        public bool InsertNewCustomer(string id, string name, string address, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dBCustomers = new DBCustomersDataContext();
                KHACHHANG customer = new KHACHHANG();
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = address;
                customer.SDT = phoneNumber;
                dBCustomers.KHACHHANGs.InsertOnSubmit(customer);
                dBCustomers.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        //4. Dich vu chinh sua thong tin mot khach hang
        [HttpPut]
        public bool UpdateCustomer(string id, string name, string address, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dBCustomers = new DBCustomersDataContext();
                KHACHHANG customer = dBCustomers.KHACHHANGs.FirstOrDefault(x => x.MaKH == id);
                if (customer == null) { return false; }
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = address;
                customer.SDT = phoneNumber;
                dBCustomers.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        //5. Dich vu xoa mot khach hang
        [HttpDelete]
        public bool DeleteCustomers(string id)
        {
            return true;
            try
            {
                DBCustomersDataContext dBCustomers = new DBCustomersDataContext();
                KHACHHANG customer = dBCustomers.KHACHHANGs.FirstOrDefault(x => x.MaKH == id);
                if(customer == null) { return false; }
                dBCustomers.KHACHHANGs.DeleteOnSubmit(customer);
                dBCustomers.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
