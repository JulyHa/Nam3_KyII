using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace BaiLam4.Models.Entity
{
    public partial class Cata_Product
    {
        public List<Categories> category { get; set; }
        public List<Products> product { get; set; }

        public Cata_Product()
        {
        }
    }
}