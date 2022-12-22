namespace NguyenThiNgu_191200758.Models.Entity
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class OrderDetails
    {
        public int Id { get; set; }

        public int OrderId { get; set; }

        [Required]
        [StringLength(10)]
        public string ProductId { get; set; }

        public double UnitPrice { get; set; }

        public int Quantity { get; set; }

        public virtual Orders Orders { get; set; }

        public virtual Products Products { get; set; }
    }
}
