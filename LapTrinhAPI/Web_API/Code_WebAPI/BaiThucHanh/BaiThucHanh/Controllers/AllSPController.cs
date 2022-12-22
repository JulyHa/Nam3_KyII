using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace BaiThucHanh.Controllers
{
    public class AllSPController : ApiController
    {
        [HttpGet]
        public List<tblSanPham> GetSanPhams()
        {
            DBContextDataContext db = new DBContextDataContext();
            return db.tblSanPhams.ToList();
        }
        [HttpGet]
        public tblSanPham GetSanPham(string id)
        {
            DBContextDataContext db = new DBContextDataContext();
            return db.tblSanPhams.FirstOrDefault(x => x.MaSP == id);
        }
    }
}
