using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
namespace TVBao
{
    class Motorcycle
    {
        public static DataTable getAllIdMotorcycle()
        {
            return ConnectDataBase.ExecuteQuery("select Bienso from Xe");
        }

        public static DataTable getDetailsMotorcycle(string id)
        {
            return ConnectDataBase.ExecuteQuery("select * from Xe p, KHACHHANG kh where  Bienso='" + id + "'and p.MaKH = kh.MaKH");
        }

        public static DataTable getAllDetailsMotorcycle(string id)
        {
            return ConnectDataBase.ExecuteQuery("select SoPhieu, kh.MaKH, Hoten, Ngaydk  from KHACHHANG kh, PHIEUDK p where kh.MaKH = p.MaKH and Bienso='"+id+"'");
        }
        public static void insert(string sophieu, string makh, string bs, string dk )
        {
            ConnectDataBase.ExecuteNonQuery("INSERT [dbo].[PHIEUDK] ([SoPhieu], [MaKH], [Bienso], [Ngaydk]) VALUES (" + sophieu + ", N'" + makh + "', N'" + bs + "', CAST(N'"+dk+"' AS Date))");
        }
        public static DataTable getAllCustomer()
        {
            return ConnectDataBase.ExecuteQuery("select HOTEN FROM KHACHHANG");
        }
        public static DataTable getMaxTicketId() {
            return ConnectDataBase.ExecuteQuery("select top 1 sophieu from PHIEUDK order by sophieu desc");
        }

    }
}
