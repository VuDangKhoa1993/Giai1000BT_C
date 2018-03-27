#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Lưu ý: thuật toán tìm kiếm nhị phân chỉ áp dụng được cho dãy đã được sắp thứ tự (tăng dần/giảm dần)
bool TimKiemNhiPhan(vector<int> &a, int x)
{
	int left = 0; int right = a.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x < a[mid])
		{
			right = mid - 1;
		}
		else if (x > a[mid])
		{
			left = mid + 1;
		}
		else //x == a[mid]
		{
			return true; //tìm thấy
		}
	}
	return false; //ko tìm thấy
}


int main()
{
	ifstream FileIn; //khai báo file cần đọc
	FileIn.open("INPUT.TXT", ios_base::in); //mở file cần đọc
	if (!FileIn)
	{
		cout << "\nfile input.txt khong ton tai !";
		system("pause");
		return 0;
	}
	//xử lý
	vector<int> a;

	//duyệt file 
	while (!FileIn.eof())
	{
		int number;
		FileIn >> number;
		a.push_back(number);
	}
	//đóng file
	FileIn.close();



	//Ghi file
	ofstream FileOut;
	FileOut.open("OUTPUT.TXT", ios_base::app); //mở file cần ghi

	//xử lý
	//duyet vector a tìm kiếm phần tử x
	int x;
	cout << "\nNhap vao phan tu can tim kiem: ";
	cin >> x;
	
	bool ketqua = TimKiemNhiPhan(a, x);

	if (ketqua == true)
	{
		FileOut << "\nPhan tu " << x << " co ton tai trong mang vector!";
	}
	else
	{
		FileOut << "\nPhan tu " << x << " khong ton tai trong mang vector!";
	}

	//dóng file
	FileOut.close();

	system("pause");
	return 0;
}