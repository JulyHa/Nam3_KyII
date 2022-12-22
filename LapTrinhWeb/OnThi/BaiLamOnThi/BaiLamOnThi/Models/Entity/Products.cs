namespace BaiLamOnThi.Models.Entity
{
    using System;
    using System.Collections.Generic;
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

        [Required(ErrorMessage ="Không được để trống")]
        [StringLength(10)]
        public string Id { get; set; }

        [Required(ErrorMessage = "Không được để trống")]
        [StringLength(50)]
        public string Name { get; set; }

        [Required(ErrorMessage = "Không được để trống")]
        [Range(100,5000, ErrorMessage ="Giá phải nằm trong khoảng 100-5000")]
        public double UnitPrice { get; set; }

        public string Image { get; set; }

        
        public bool Available { get; set; }

        public int CategoryId { get; set; }

        [DataType(DataType.MultilineText)]
        public string Description { get; set; }

        public virtual Categories Categories { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<OrderDetails> OrderDetails { get; set; }
    }
}
