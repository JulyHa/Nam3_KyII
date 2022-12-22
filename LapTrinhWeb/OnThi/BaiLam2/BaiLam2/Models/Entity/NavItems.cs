namespace BaiLam2.Models.Entity
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class NavItems
    {
        public int Id { get; set; }

        [Required]
        [StringLength(50)]
        public string NavName { get; set; }

        [StringLength(50)]
        public string NavNameVN { get; set; }
    }
}
