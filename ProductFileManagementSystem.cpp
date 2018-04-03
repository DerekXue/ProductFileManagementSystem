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
		unsigned char k = 0x80;	//二进制表达式为 : 10000000
		for (int z = 0; z < 8; z++, k >>= 1){	//这里的>>为二进制右移运算符(不是流运算符)，k>>=1：每次循环把k最高位的1往右移动一位
			if (str[i] & k){	//&为二进制与运算符：str[i] AND k 结果为1(true) 或 0(false)
				storeStr += "1";	//由于 str[i]字节 的每一位和1做与运算，所以结果为str[i]字节 二进制表达式 每一位上本身的值
			}
			else{
				storeStr += "0";	//由于 str[i]字节 的每一位和1做与运算，所以结果为str[i]字节 二进制表达式 每一位上本身的值
			}
		}
		storeStr += " ";	//每8位空一格
	}
	return storeStr;	//storeStr为str的二进制表达式
}

void binToStr(string fileName){	//把二进制转换为字符串 然后输出到控制台的算法
	FILE *fptr;
	#pragma warning(disable:4996) //supress the warning of fopen()
	fptr = fopen(fileName.c_str(), "r");
	char myline[9999];
	while (!feof(fptr)){	//遍历打开文本的全部内容
		fgets(myline, 9999, fptr);	//文本内容存入 char类型变量 myline
		istringstream in(myline);	//把char类型 转换成 字符串流类型 in
		bitset<8> bs;	//初始化bs二进制表达式 ： 00000000
		while (in >> bs)	//这里的>>为流运算符，把存有文本内容的字符串流 赋值给 二进制变量bs
		{
			cout << char(bs.to_ulong());	//把bs转换为 char类型的 长整型 并输出到console
		}
		cout << "\n";
	}
	fclose(fptr);	//遍历完毕后关闭文本
}

class add_Product :public product_Information{
public:

	void function1(){
		system("CLS");	//CLS=clear string
		cout << "\t\t\t\tADD FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"){	//让用户给变量赋值
			cin.ignore();
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
			if (confirmation == "Y"){	//调用strToBin函数
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
		system("CLS");	
		cout << "\t\t\t\tSEARCH FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"){
			cin.ignore();
			cout << "please enter Product_Name" << endl;
			getline(cin, Product_Name);
			ifstream inputFile;
			inputFile.open(Product_Name);	//根据输入索引打开文件
			if (inputFile.is_open()){
				cout << "\n";
				cout << "***********************************" << endl;
				binToStr(Product_Name);	//调用binToStr函数
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
		system("CLS");	
		cout << "\t\t\t\tEDIT FUNCTION" << endl;
		cout << "\t\t\t-----------------------------" << endl;
		while (confirmation != "N"&&flag){
			cin.ignore();
			cout << "please enter Product_Name you want to update" << endl;
			getline(cin, Product_Name);
			ifstream inputFile;
			inputFile.open(Product_Name);
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
					cin.clear();	
					cin.sync();
					cin >> confirmation;
					if (confirmation != "Y")	//flag用于处理如果有人在这里输入非Y或N时的情况
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
		system("CLS");
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
				inputFile.open(Product_Name);
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
	system("CLS");
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
			cin.clear();	//cin.clear()和cin.sync()连用的作用是 清除缓存区中上一次cin的输入值，
			cin.sync();	//否则如果有人输入 非1-5的整数 时，这里会进入无限循环
			cout << "Invalid input Please select again" << endl;
			cin >> functionChoose;	//重新cin值
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
