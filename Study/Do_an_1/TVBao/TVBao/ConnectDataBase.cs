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
    class ConnectDataBase
    {
        private static SqlConnection connect = new SqlConnection();

        public static void OpenDataBase()
        {
            string sqlServer = @"Data Source = M35\SQLEXPRESS; Initial Catalog = DANGKIEM; Integrated Security = True";
            connect.ConnectionString = sqlServer;
            if (connect.State == ConnectionState.Closed) connect.Open();
        }

        public static void CloseDataBase()
        {
           
            if (connect.State != ConnectionState.Closed) connect.Close();
        }

        public static DataTable ExecuteQuery(string sql)
        {
            OpenDataBase();
            DataTable data = new DataTable();
            SqlCommand cd = new SqlCommand(sql, connect);
            SqlDataReader dr = cd.ExecuteReader();
            data.Load(dr);
            CloseDataBase();
            return data;
        }

        public static void ExecuteNonQuery(string sql)
        {
            OpenDataBase();
            SqlCommand cd = new SqlCommand(sql, connect);
            cd.ExecuteNonQuery();
            CloseDataBase();
        }
    }
}
