using System.Web;
using System.Web.Mvc;

namespace NguyenThiNgu_191200758
{
    public class FilterConfig
    {
        public static void RegisterGlobalFilters(GlobalFilterCollection filters)
        {
            filters.Add(new HandleErrorAttribute());
        }
    }
}
