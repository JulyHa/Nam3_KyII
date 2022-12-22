namespace BaiLam4.Models.Entity
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Products
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Products()
        {
            OrderDetails = new HashSet<OrderDetails>();
        }

        [StringLength(10)]// /^[A-Z]{2}[0-9]{4}$/
        [Required(ErrorMessage = "Không được để trống")]
        [RegularExpression("[A-Z]{2}[0-9]{4}$", ErrorMessage = "ID có dạng XX0000")]
        [DisplayName("Product ID")]
        public string Id { get; set; }

        [Required]
        [StringLength(50)]
        public string Name { get; set; }

        public double UnitPrice { get; set; }

        public string Image { get; set; }

        public bool Available { get; set; }

        public int CategoryId { get; set; }

        public string Description { get; set; }

        public virtual Categories Categories { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<OrderDetails> OrderDetails { get; set; }
    }
}
