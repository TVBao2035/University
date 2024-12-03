#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien
{
    int msv, ngaysinh, thangsinh, namsinh, tuoi;
    string hoten, gioitinh, diachi;
    float diemtoan, diemli, diemhoa;

    void nhap1msv()
    {
        do
        {
            cout << "\nNhap Ma Sinh Vien:";
            cin >> msv;
            if (msv > 99999 || msv < 10000)
            {
                cout << "\n[?].Ma Sinh Vien Chi Gom 5 Chu So. Vui Long Nhap Lai!\n";
            }
        } while (msv > 99999 || msv < 10000);
    }

   string chongioitinh()
   {
    int c;
    cout <<"\nChon Gioi Tinh:";
    cout <<"\n1.Nam";
    cout <<"\n2.Nu";
    cout <<"\n[?].Nhap Lenh:";
    cin >> c;
    switch(c)
    {
     case 1: gioitinh ="Nam";
     break;
     case 2: gioitinh ="Nu";
     break;
    }
    return gioitinh;
   }

    void nhap1tt()
    {
        cout << "\n[?].Nhap Ho Ten Sinh Vien:";
        fflush(stdin);
        getline(cin, hoten);
        cout <<"\n[?].Ngay Sinh "; cin >> ngaysinh;
        cout <<"[?].Thang Sinh "; cin >> thangsinh;
        cout <<"[?].Nam Sinh "; cin >> namsinh;
        chongioitinh();
        cout <<"\n[?].Nhap Dia Chi Sinh Vien:";
        fflush(stdin);
        getline(cin,diachi);
        cout << "\n[?].Nhap Diem Toan:";
        cin >> diemtoan;
        cout << "\n[?].Nhap Diem Ly:";
        cin >> diemli;
        cout << "\n[?].Nhap Diem Hoa:";
        cin >> diemhoa;
    }

    float diemtb()
    {
     float ketqua;
     ketqua = (diemtoan + diemli + diemhoa)/3;
     return ketqua;
    }

    int tinhtuoi()
    {
      return 10000 - namsinh;
    }

    string hocluc()
    {
     string ketqua;
     if(diemtb() >= 8) 
     {
         ketqua ="Gioi";
     } 
     else if(diemtb() >= 7 )
          {
            ketqua ="Kha";
          }
     else if(diemtb() >= 5 )
          {
            ketqua ="Trung Binh";
          }
    else 
    {
        ketqua ="Yeu";
    }
     return ketqua;  
    }
    
   void intt1sv()
   {
    cout << endl;
    cout << left << setw(2) <<"|";
    cout << left << setw(6) << msv;
    cout << left << setw(2) <<"|";
    cout << left << setw(21) << hoten;
    cout << left << setw(6) <<"|";
    cout << left << setw(2) << ngaysinh << setw(1) <<"/"<< setw(2)<< thangsinh <<setw(1) <<"/"<< setw(11) << namsinh;
    cout << left << setw(5) <<"|";
    cout << left << setw(7) <<gioitinh;
    cout << left << setw(7) <<"|";
    cout << left << setw(18) << diachi;
    cout << left << setw(2) <<"|";
   }
    
    void indiem1sv()
    {
        cout << endl;
        cout << left << setw(2) << "|";
        cout << left << setw(6) << msv;
        cout << left << setw(2) << "|";
        cout << left << setw(21) << hoten;
        cout << left << setw(7) << "|";
        cout << left << setw(8) << diemtoan;
        cout << left << setw(7) << "|";
        cout << left << setw(8) << diemli;
        cout << left << setw(7) << "|";
        cout << left << setw(8) << diemhoa;
        cout << left << setw(7) << "|";
        cout << left << setw(8) << diemtb();
        cout << left << setw(3) <<"|"; 
        cout << left <<setw(12) << hocluc();
        cout << left <<setw(7) <<"|";
        
    }
};

int L=107;
int N =15;
SinhVien x;
void khungdiem()
{
    for (int i = 1; i <= L; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << left << setw(3) << "|";
    cout << left << setw(5) << "MSV";
    cout << left << setw(6) << "|";
    cout << left << setw(17) << "Ho & Ten";
    cout << left << setw(3) << "|";
    cout << left << setw(12) << "Diem Toan";
    cout << left << setw(4) << "|";
    cout << left << setw(11) << "Diem ly";
    cout << left << setw(4) << "|";
    cout << left << setw(11) << "Diem Hoa";
    cout << left << setw(4) << "|";
    cout << left << setw(11) <<"Diem TB";
    cout << left << setw(4) <<"|";
    cout << left << setw(11) <<"Hoc Luc";
    cout << left << setw(3) <<"|";

    cout << endl;
    for (int i = 1; i <= L; i++)
    {
        cout << "-";
    }
    cout<<endl;
}

void khungtt()
{
 for (int i = 1; i <= L-N; i++)
 {
  cout << "-";
 }
 cout << endl;
 cout << left << setw(3) <<"|";
 cout << left << setw(5) <<"MSV";
 cout << left << setw(6) <<"|";
 cout << left << setw(17) <<"Ho & Ten";
 cout << left <<setw(3) <<"|";
 cout << left << setw(20) <<"Ngay/Thang/Nam Sinh";
 cout << left << setw(2) <<"|";
 cout << left << setw(10) <<"Gioi Tinh";
 cout << left << setw(9) <<"|";
 cout << left << setw(16) <<"Dia Chi";
 cout << left << setw(2) <<"|";
 cout << endl;
for (int i = 1; i <= L-N; i++)
 {
  cout << "-";
 }
 cout<<endl;
}

void nhapsv(SinhVien sv[], int n)
{ 
 for(int i=1; i<=n ;i++)
 {  
    sv[i].nhap1msv();  
    sv[i].nhap1tt();
 }
}    
 
 void inttsv(SinhVien sv[], int n)
 {
  khungtt();
  for(int i=1; i<=n ;i++)
  {
   sv[i].intt1sv();
  }
  cout << endl;
  for(int i=1; i<=L-N; i++)
  { 
   cout <<"-"; 
  }
  cout<<endl;
 }
 void dem(SinhVien sv[], int n)
 {
    int demG = 0, demK=0, demTB=0, demY =0;
    for(int i = 1; i<=n ; i++)
    {
      if(sv[i].hocluc()=="Gioi")
      {
        demG++;
      }
      else if(sv[i].hocluc()=="Kha")
      {
        demK++;
      }
      else if(sv[i].hocluc()=="Trung Binh")
      {
        demTB++;
      }
      else 
      {
        demY++;
      }
    }
      cout <<"\n-So Sinh Vien Dat Loai Gioi la "<<demG;
      cout <<"\n-So Sinh Vien Dat Loai Kha la "<<demK;
      cout <<"\n-So Sinh Vien Dat Loai Trung Binh la "<<demTB;
      cout <<"\n-So Sinh Vien Dat Loai Yeu la "<<demY<<endl;
    
 }
 void indiemsv(SinhVien sv[], int n)
 {
  khungdiem();
  for(int i=1; i<=n ;i++)
  {
   sv[i].indiem1sv();
  }
  cout << endl;
  for(int i=1; i<=L; i++)
  { 
   cout <<"-"; 
  }
  cout<<endl;
 }

  bool testmsv(SinhVien sv[], int n)
 {
   bool ketqua = false;
   int dem = 0;
   for(int i =1; i < n ; i++)
   {
    if(sv[n].msv == sv[i].msv)
    { 
      ketqua=true;
    }
   }
    return ketqua;
   }
   
 void findmsv(SinhVien sv[], int n)
 {
   int find;
   int save =0;
   cout<<"\n[?].Nhap Ma Sinh Vien:";
   cin>>find;
   for(int i = 1; i <= n;i++)
   {
    if(sv[i].msv == find)
    {
      save = i;
    }
   }
   if(save==0)
   {
    cout<<"\n[!].Khong Tim Thay Ma Sinh Vien { "<<find<<" }";
   }
   else
   {
      khungtt();
      sv[save].intt1sv();
      cout<<endl;
      for (int i = 1; i <= L-N; i++)
      {
          cout << "-";
      }
      cout<<endl;

   }
 }
 void find_name( SinhVien sv[], int &n)
 {
  string name_find = "not person";
  int save = 0;
  cout<<"\n[?].Nhap Ten Can Tim:";
  fflush(stdin);
  getline(cin,name_find);
  for(int i = 1;i<=n;i++)
  {
    if(name_find == sv[i].hoten){
      save = i;
      break;
    }else{save = -1;}
  }
  if(save < 0){
    cout<<"\n[!].Khong Tim Thay Ten Sinh Vien "<<name_find<<endl;
  }else{
    khungtt();
    sv[save].intt1sv();
    cout<<endl;
    for(int i = 1;i<L-N; i++)
    {
      cout<<"-";
    }
    cout<<endl;
  }
 }
 void timkiem( SinhVien sv[], int n)
 {
    int c;
    cout<<"\n1.Tim Kiem Bang Ma Sinh Vien.";
    cout<<"\n2.Tim Kiem Bang Ten Sinh Vien.";
    cout<<"\n\n[?].Nhap Lenh:";
    cin>>c;
    switch(c)
    {
      case 1:
        findmsv(sv,n);
        break;
      case 2:
        find_name(sv,n);
        break;
    }
 }

  void chen( SinhVien sv[], int &n)
  {
    n++;
    do
    { 
      sv[n].nhap1msv();
      if(testmsv(sv,n))
      {
        cout<<"\n[!].Ma Sinh Vien Da Ton Tai.Vui Long Nhap Lai!";
      }
    } while (testmsv(sv,n));
    sv[n].nhap1tt();
    inttsv(sv,n);
  }

  void xoa(SinhVien sv[], int &n)
  {
    int vitrixoa;
    cout <<"\n[?].Nhap Vi Tri Can Xoa:";
    cin >> vitrixoa;
    for(int i = vitrixoa; i <= n; i++)
    {
      sv[i] = sv[i+1];
    }
    n--;
     inttsv(sv,n);
  }

 void sapxeptuoi(SinhVien sv[], int n)
 {

    for(int i=1; i < n;i++)
    {
        for(int j=i+1; j<=n;j++)
        {
            if(sv[i].tinhtuoi()<sv[j].tinhtuoi())
            {
                x = sv[i];
                sv[i] = sv[j];
                sv[j] = x;
            }
        }
    }
    inttsv(sv,n);
 }

 void sapxepdiemtb(SinhVien sv[],int n)
 {
  
    for(int i=1;i < n;i++)
    {
        for(int j=i+1; j <= n;j++)
        {
            if(sv[i].diemtb() < sv[j].diemtb())
            {
             x = sv[i];
             sv[i] = sv[j];
             sv[j] = x;
            }
        }
    }
    indiemsv(sv,n);
 }

 void sapxeptoan(SinhVien sv[], int n)
 {

   for(int i=1; i < n ; i++)
   {
    for(int j= i+1; j <= n;j++)
    {
        if(sv[i].diemtoan < sv[j].diemtoan)
        {
            x = sv[i];
            sv[i]  = sv[j];
            sv[j] = x;
        }
    }
   }
   indiemsv(sv,n);
 }

 void sapxepli(SinhVien sv[], int n)
 {
    
    for(int i=1; i < n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(sv[i].diemli < sv[j].diemli)
            {
             x = sv[i];
             sv[i] = sv[j];
             sv[j] = x;
            }
        }
    }
    indiemsv(sv,n);
 }

 void sapxephoa(SinhVien sv[], int n)
 {
 
    for(int i = 1; i< n; i++)
    {
        for(int j = i+1; j <= n ; j++)
        {
            if(sv[i].diemhoa < sv[j].diemhoa)
            {
                x = sv[i];
                sv[i] = sv[j];
                sv[j] = x;
            }
        }
    }
    indiemsv(sv,n);
 }


 void sapxep(SinhVien sv[], int n)
 {
    int c;
    cout <<"\n  ======SAP XEP======";
    cout <<"\n(1).Sap Xep Tuoi";
    cout <<"\n(2).Sap Xep Diem Trung Binh";
    cout <<"\n(3).Sap Xep Diem Toan";
    cout <<"\n(4).Sap Xep Diem Li";
    cout <<"\n(5).Sap Xep Diem Hoa";
    cout <<"\n[!].Nhap Lenh:";
    cin >> c;
    switch(c)
    {
        case 1:
        sapxeptuoi(sv,n);
        break;
        case 2:
        sapxepdiemtb(sv,n);
        break;
        case 3:
        sapxeptoan(sv,n);
        break;
        case 4:
        sapxepli(sv,n);
        break;
        case 5:
        sapxephoa(sv,n);
        break;

    }
 }

void menu(SinhVien sv[], int n)
{
  for(;;)
  {
    int c;
    system("cls");
    cout <<"\n=========== MENU ===========";
    cout <<"\n(1).Thong Tin Sinh Vien";
    cout <<"\n(2).Diem Sinh Vien";
    cout <<"\n(3).Them Sinh Vien";
    cout <<"\n(4).Xoa Mot Sinh Vien";
    cout <<"\n(5).Sap Xep";
    cout<<"\n(6).Tim Kiem Sinh Vien";
    cout <<"\n[!] Nhap Lenh:";
    cin >> c;
    switch(c)
    {
     case 1:
     inttsv(sv,n);
     system("pause");
     break;
     case 2:
     indiemsv(sv,n);
     dem(sv,n);
     system("pause");
     break;
     case 3:
     chen(sv,n);
     system("pause");
     break;
     case 4:
     xoa(sv,n);
     system("pause");
     break;
     case 5:
     sapxep(sv,n);
     system("pause");
     break;
     case 6:
     timkiem(sv,n);
     system("pause");
     break;

   }
 }
}
int main()
{
    SinhVien sv[1000];
    int n=0;
    menu(sv,n);

    return 0;
}