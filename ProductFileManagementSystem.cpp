#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <bitset>
#include <sstream>
using namespace std;

class product_Information{
protected:
	string Product_Name;
	string Product_ID;
	string Manufacture_date;
	string price;
	string Brand;
	string Expiary_Date;
	string confirmation;

	string Product_Name_Bin;
	string Product_ID_Bin;
	string Manufacture_date_Bin;
	string price_Bin;
	string Brand_Bin;
	string Expiary_Date_Bin;
};

string strToBin(string str){	//把字符串转换为二进制 然后输出到文本的算法
	string storeStr;
	for (int i = 0; i<str.length(); i++){
		unsigned char k = 0x80;
		for (int z = 0; z < 8; z++, k >>= 1){
			if (str[i] & k){	//c AND k = 1 = true
				storeStr += "1";
			}
			else{
				storeStr += "0";
			}
		}
		storeStr += " ";
	}
	return storeStr;
}

void binToStr(string fileName){	//把二进制转换为字符串 然后输出到控制台的算法
	FILE *fptr;
#pragma warning(disable:4996) //supress the warning for fopen()
	fptr = fopen(fileName.c_str(), "r");
	char myline[9999];
	while (!feof(fptr)){
		fgets(myline, 9999, fptr);
		istringstream in(myline);
		bitset<8> bs;
		while (in >> bs)
		{
			cout << char(bs.to_ulong());
		}
		cout << "\n";
	}
	fclose(fptr);
}

class add_Product :public product_Information{
public:

	void function1(){
		system("CLS");//CLS=clear string
		cout << "\t\t\t\tADD FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"){
			cin.ignore();
			//让用户给变量赋值
			cout << "please enter Product_Name" << endl;
			getline(cin, Product_Name);
			cout << "please enter Product_ID" << endl;
			getline(cin, Product_ID);
			cout << "please enter Manufacture_date" << endl;
			getline(cin, Manufacture_date);
			cout << "please enter price" << endl;
			getline(cin, price);
			cout << "please enter Brand" << endl;
			getline(cin, Brand);
			cout << "please enter Expiary_Date" << endl;
			getline(cin, Expiary_Date);
			cout << "\n";
			cout << "Confirm add this stock?(Y/N)" << endl;
			cin >> confirmation;
			if (confirmation == "Y"){
				//调用stringToBinary函数
				ofstream outputFile(Product_Name);
				outputFile << strToBin("Product_Name : ") << strToBin(Product_Name) << endl;
				outputFile << strToBin("Product_ID : ") << strToBin(Product_ID) << endl;
				outputFile << strToBin("Manufacture_date : ") << strToBin(Manufacture_date) << endl;
				outputFile << strToBin("price : ") << strToBin(price) << endl;
				outputFile << strToBin("Brand : ") << strToBin(Brand) << endl;
				outputFile << strToBin("Expiary_Date : ") << strToBin(Expiary_Date) << endl;
				cout << "\n";
				cout << "Product : " << Product_Name << " is added to the Same Directory as this cpp file" << endl;
				cout << "\n";
				cout << "Add another file?(Y/N)" << endl;
				cin >> confirmation;
			}
			else
			{
				cout << "\n";
				cout << "Add Product : "<< Product_Name<<" Failed" << endl;
				cout << "\n";
				cout << "Add another Product?(Y/N)" << endl;
				cin >> confirmation;
			}
		}
	}
};

class search_Product :public product_Information{
public:

	void function2(){
		system("CLS");//CLS=clear string
		cout << "\t\t\t\tSEARCH FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"){
			cin.ignore();
			cout << "please enter Product_Name" << endl;
			getline(cin, Product_Name);
			//根据输入索引打印文件内容
			ifstream inputFile;
			inputFile.open(Product_Name);//打开文件
			if (inputFile.is_open()){
				cout << "\n";
				cout << "***********************************" << endl;
				binToStr(Product_Name);
				cout << "***********************************" << endl;
				cout << "\n";
			}
			else{
				cout << "\n";
				cout << "Product " << Product_Name << " is Not Found" << endl;
			}
			cout << "\n";
			cout << "Search Again?(Y/N)" << endl;
			cin >> confirmation;
		}
	}
};

class edit_Product :public product_Information{
	char changeConfirmation;
	bool flag = true;
public:
	void function3(){	
		system("CLS");//CLS=clear string
		cout << "\t\t\t\tEDIT FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"&&flag){
			cin.ignore();
			cout << "please enter Product_Name you want to update" << endl;
			getline(cin, Product_Name);
			//根据输入索引打印文件内容
			ifstream inputFile;
			inputFile.open(Product_Name);//打开文件
			if (inputFile.is_open()){
				cout << "please enter the new Product_ID" << endl;
				getline(cin, Product_ID);
				cout << "please enter the new Manufacture_date" << endl;
				getline(cin, Manufacture_date);
				cout << "please enter the new price" << endl;
				getline(cin, price);
				cout << "please enter the new Brand" << endl;
				getline(cin, Brand);
				cout << "please enter the new Expiary_Date" << endl;
				getline(cin, Expiary_Date);
				cout << "Confirm change this stock?(Y/N)" << endl;
				cin >> changeConfirmation;
				if (changeConfirmation == 'Y'){
					//输出变量到File Output
					ofstream outputFile(Product_Name);
					outputFile << strToBin("Product_Name : ") << strToBin(Product_Name) << endl;
					outputFile << strToBin("Product_ID : ") << strToBin(Product_ID) << endl;
					outputFile << strToBin("Manufacture_date : ") << strToBin(Manufacture_date) << endl;
					outputFile << strToBin("price : ") << strToBin(price) << endl;
					outputFile << strToBin("Brand : ") << strToBin(Brand) << endl;
					outputFile << strToBin("Expiary_Date : ") << strToBin(Expiary_Date) << endl;
					cout << "\n";
					cout << "Change is Made to Product : " << Product_Name << endl;
					cout << "\n";
					cout << "Change another Product?(Y/N)" << endl;
					cin >> confirmation;
				}
				else
				{
					cout << "\n";
					cout << "Change is Not made to Product : " << Product_Name << endl;
					cout << "\n";
					cout << "Change another Product?(Y/N)" << endl;
					cin.clear();	//处理如果有人输入非Y或N时的情况
					cin.sync();
					cin >> confirmation;
					if (confirmation != "Y")
					{
						flag = false;
					}
					else
					{
						flag = true;
					}
				}
			}
			else{
				cout << "\n";
				cout << "Error occured when opening Product : " << Product_Name << endl;
				cout << "\n";
				cout << "Search Again?(Y/N)" << endl;
				cin >> confirmation;
			}

		}
	}
};

class delete_Product :public product_Information{
public:
	void function4(){
		system("CLS");//CLS=clear string
		cout << "\t\t\t\tDELETE FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"){
			cin.ignore();
			cout << "please enter Product_Name you want to delete" << endl;
			getline(cin, Product_Name);
			cout << "\n";
			cout << "Do you confirm delete product " << Product_Name << " ? (Y for confirm)" << endl;
			cin >> confirmation;
			if (confirmation == "Y"){
				ifstream inputFile;
				inputFile.open(Product_Name);//打开文件
				if (inputFile.is_open()){
					inputFile.close();
					remove(Product_Name.c_str());	//.remove()的参数是char类型，不可以是string类型
					cout << "\n";
					cout << "Product " << Product_Name << " Removed" << endl;
				}
				else{
					cout << "\n";
					cout << "Product " << Product_Name << "is Not Found" << endl;
				}
			}
			else{
				cout << "\n";
				cout << "Change is Not made to Product : " << Product_Name << endl;
			}
			cout << "\n";
			cout << "Delete another Product?(Y/N)" << endl;
			cin >> confirmation;
		}
	}
};

void menuScreen(){	//回调函数
	system("CLS");//CLS=clear string
	cout << "\t\t\t\tMAIN MENU" << endl;
	cout << "\t\t\t-----------------------------" << endl;
	int functionChoose = 0;
	add_Product myAdd;
	search_Product mySearch;
	edit_Product myEdit;
	delete_Product myDelete;
	cout << "\n";
	cout << "\tChoose Function number 1 to 4 :" << endl;
	cout << "\t******************************************************" << endl;
	cout << "\t* Enter 1 ---> Create a new product description file *" << endl;
	cout << "\t* Enter 2 ---> Search for a product description      *" << endl;
	cout << "\t* Enter 3 ---> Update a product description file     *" << endl;
	cout << "\t* Enter 4 ---> Delete a product description file     *" << endl;
	cout << "\t* Enter 5 ---> Quit program                          *" << endl;
	cout << "\t******************************************************" << endl;
	cin >> functionChoose;
	while (functionChoose != 1 || 2 || 3 || 4 || 5){
		if (functionChoose == 1){
			myAdd.function1();
			menuScreen();	//回调
			return;
		}
		else if (functionChoose == 2){
			mySearch.function2();
			menuScreen();
			return;
		}
		else if (functionChoose == 3){
			myEdit.function3();
			menuScreen();
			return;
		}
		else if (functionChoose == 4){
			myDelete.function4();
			menuScreen();
			return;
		}
		else if (functionChoose == 5){
			return;
		}
		else
		{
			cin.clear();//cin.clear()和cin.sync()连用的作用是 清除缓存区中上一次cin的输入值，
			cin.sync();//否则如果有人 输入超出int范围的数，这里会进入无限循环
			cout << "Invalid input Please select again" << endl;
			cin >> functionChoose;//重新cin值
		}
	}
}

void main()
{
	menuScreen();
	cout << "\n";
	cout << "\t\t***********************************" << endl;
	cout << "\t\t* Thank you for using this system *" << endl;
	cout << "\t\t*           Good day              *" << endl;
	cout << "\t\t***********************************" << endl;
	cout << "\n";
	system("pause");
}
