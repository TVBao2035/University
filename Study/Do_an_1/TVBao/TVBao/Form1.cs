using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TVBao
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public void addDataListIdMotorcycle()
        {
            DataTable data = new DataTable();
            data = Motorcycle.getAllIdMotorcycle();
            listIdMotorcyles.DataSource = data;
            listIdMotorcyles.DisplayMember = "Bienso";
            listIdMotorcyles.ValueMember = "Bienso";

        }
        private void listIdMotorcyles_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        public void addCustomer()
        {
            DataTable data = new DataTable();
            data = Motorcycle.getAllCustomer();
            comboCustomers.DataSource = data;
            comboCustomers.DisplayMember = "Hoten";
            comboCustomers.ValueMember = "MaKH";
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            addDataListIdMotorcycle();
            addCustomer();
        }
        public void displayInformation()
        {
            listCustomers.Items.Clear();
            DataTable data = new DataTable();
            data = Motorcycle.getAllDetailsMotorcycle(listIdMotorcyles.SelectedValue.ToString());
            int length = data.Rows.Count;
            for(int i=0; i<length; i++)
            {
                listCustomers.Items.Add(data.Rows[i][0].ToString());
                listCustomers.Items[i].SubItems.Add(data.Rows[i][1].ToString());
                listCustomers.Items[i].SubItems.Add(data.Rows[i][2].ToString());
                listCustomers.Items[i].SubItems.Add(data.Rows[i][3].ToString());
            }
        }
        private void listIdMotorcyles_Click(object sender, EventArgs e)
        {
            DataTable data = new DataTable();
            data = Motorcycle.getDetailsMotorcycle(listIdMotorcyles.SelectedValue.ToString());
            txtId.Text = data.Rows[0]["Bienso"].ToString();
            dateEnd.Text = data.Rows[0]["Ngayhethan"].ToString();
            comboCustomers.Text = data.Rows[0]["Hoten"].ToString();

            displayInformation();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string sophieu = (int.Parse(Motorcycle.getMaxTicketId().Rows[0][0].ToString())+1).ToString();
            string makh = comboCustomers.SelectedValue.ToString();
            string bs = txtId.Text;
            string date = dateEnd.Value.ToString("MM/dd/yyyy");
            Motorcycle.insert(sophieu, makh, bs, date);
            displayInformation();
        }
    }
}
