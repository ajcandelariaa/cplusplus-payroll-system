#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct People{
	char lname[30], fname[30], mname[30];
};

void home();
void payroll();
void delete_employee();
void add(struct People *info);

int main()
{
	char home_choice;
	People info;
	home();
	cin >> home_choice;
	while(home_choice != '1' && home_choice != '2' && home_choice != '3' && home_choice != '4')
	{
		cout << "Invalid Input!" << endl;
		cout << "Please enter the correct choice!" << endl;
		cout << "Choice: ";
		cin >> home_choice;
	}
	system("cls");
	switch(home_choice)
	{
		case '1': system("Cls"); add(&info); break;
		case '2': system("cls"); payroll(); break;
		case '3': system("cls"); delete_employee(); break;
		case '4': system("pause"); exit(0); break;
	}
	
}

void home()
{
	cout << "================================" << endl;
	cout << "\tPayroll System" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "[1] Register Employee" << endl;
	cout << "[2] Show Employees" << endl;
	cout << "[3] Delete Employee" << endl;
	cout << "[4] Exit" << endl;
	cout << "Choice: ";
}

void add(struct People *info)
{
	int id, x=0;
	char choice;
	cout << "================================" << endl;
	cout << "\tPayroll System" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "REGISTRATION" << endl;
	ifstream count_employee("ID.txt");
		while(count_employee >> id)
		{
			x=id;
		}
	count_employee.close();
	cout << "Employee ID: " << x+1 << endl;
	cout << "Lastname: ";
	cin.ignore(); //delete new line
	cin.getline(info->lname, 30);
	cout << "Firstname: ";
	cin.getline(info->fname, 30);
	cout << "Middlename: ";
	cin.getline(info->mname, 30);
	
	ofstream ids("ID.txt", ios::out | ios::app);
	ofstream lname("Lastname.txt", ios::out | ios::app);
	ofstream fname("Firstname.txt", ios::out | ios::app);
	ofstream mname("Middlename.txt", ios::out | ios::app);
	ids << x+1 << endl;
	lname << info->lname << endl;
	fname << info->fname << endl;
	mname << info->mname << endl;
	ids.close(); lname.close(); fname.close(); mname.close();
	
	cout << "Record Successfully Added!" << endl;
	cout << endl << "[1] Home" << endl;
	cout << "[2] Exit" << endl;
	cout << "Choice: ";
	cin >> choice;
	while(choice != '1' && choice != '2')
	{
		cout << "Invalid Input!" << endl;
		cout << "Please enter the correct choice!" << endl;
		cout << "Choice: ";
		cin >> choice;
	}
	switch (choice)
	{
		case '1': system("cls"); main(); break;
		case '2': system("pause"); exit(0); break;
	}
}

void payroll()
{
	payroll:
	int id, get_id, x=0, temp_id, j=0;
	string lname, fname, mname, lnames, fnames, mnames;
	string store_lnames[60], store_fnames[60], store_mnames[60];
	char salary_choice;
	
	ifstream show_id("ID.txt");
	ifstream show_lname("Lastname.txt");
	ifstream show_fname("Firstname.txt");
	ifstream show_mname("Middlename.txt");
	
	cout << "List of Employee:" << endl;
	cout << "\tID Number\t\tLastname\t\tFirstname\t\tMiddlename" << endl;
	while(show_id >> id && getline(show_lname,lname) && getline(show_fname, fname) && getline(show_mname, mname))
	{
		cout << left <<"\t   " << setw(21) << id << setw(24)  << lname << setw(24)  << fname  << mname << endl;
		j++;
	}
	if(j==0)
	{
		cout << endl << endl << "No Records Listed" << endl;
		char choice4;
		cout << "[1] Home" << endl;
		cout << "[2] Exit" << endl;
		cout << "Choice: ";
		cin >> choice4;
		while(choice4 != '1' && choice4 != '2')
		{
			cout << "Invalid Input!" << endl;
			cout << "Please enter the correct choice!" << endl;
			cout << "Choice: ";
			cin >> choice4;
		}
		switch (choice4)
		{
			case '1': system("cls"); main(); break;
			case '2': system("pause"); exit(0); break;
		}
	}
	show_id.close(); show_lname.close(); show_fname.close(); show_mname.close();
	
	cout << "Do you want to calculate their salary Y/N ? ";
	cin >> salary_choice;
	while(toupper(salary_choice) != 'Y' && toupper(salary_choice) != 'N')
	{
		cout << "Invalid Input!" << endl;
		cout << "Please enter the correct choice!" << endl;
		cout << "Choice: ";
		cin >> salary_choice;
	}
	if(toupper(salary_choice) == 'Y')
	{	
		cout << "Enter the ID Number: ";
		cin >> get_id;
		cout << endl << endl;
		ifstream show_id("ID.txt");
		ifstream show_lname("Lastname.txt");
		ifstream show_fname("Firstname.txt");
		ifstream show_mname("Middlename.txt");
		
		while(getline(show_lname,lnames) && getline(show_fname, fnames) && getline(show_mname, mnames))
		{
			store_lnames[x] = lnames;
			store_fnames[x] = fnames;
			store_mnames[x] = mnames;
			x++;
		}
		
		while(show_id >> temp_id)
		{
			if(get_id == temp_id)
			{
				int others=0, total=0, cash_advance=0, deduct=0, working_days=0;
				char choice2, choice_r;
				cout << "-------------------------------------------" << endl;
				cout << setw(28) << "Employee Number: "<< get_id << endl;
				cout << setw(28) << "Lastname: " << store_lnames[get_id-1] << endl;
				cout << setw(28) << "Firstname: " << store_fnames[get_id-1] << endl;
				cout << setw(28) << "Middlename: " << store_mnames[get_id-1] << endl;
				cout << "-------------------------------------------" << endl;
				cout << setw(28) << "Rate per day: " << "P250" << endl;
				cout << setw(28) << "Enter Working Days: ";
				cin >> working_days;
				total = working_days * 250;
				cout << setw(28) << "Grosspay: " << total << endl;
				cout << "-------------------------------------------" << endl;
				cout << setw(28) << "Cash Advance: ";
				cin >> cash_advance;
				cout << setw(28) << "SSS: " << "130" << endl;
				cout << setw(28) << "Phil Health: " << "160" << endl;
				cout << setw(28) << "Pagibig: " << "150" << endl;
				cout << setw(28) << "Others: ";
				cin >> others;
				deduct = 130 + 160 + 150 + cash_advance + others;
				cout << setw(28) << "Deductions: " << deduct << endl;
				cout << "-------------------------------------------" << endl;
				cout << setw(28) << "Netpay: " << total - deduct << endl;
				cout << "-------------------------------------------" << endl << endl;
				cout << "Do you want a receipt Y/N: ";
				cin >> choice_r;
				while(toupper(choice_r) != 'Y' && toupper(choice_r) != 'N')
				{
					cout << "Invalid Input! Please enter the correct choice!" << endl;
					cout << "Choice: ";
					cin >> choice_r;
				}
				if(toupper(choice_r) == 'Y')
				{
					ofstream f_receipt("Receipt.txt");
					
					f_receipt << "-------------------------------------------" << endl;
					f_receipt << left << setw(28) << "Employee Number: " << get_id << endl;
					f_receipt << left << setw(28) << "Lastname: " << store_lnames[get_id-1] << endl;
					f_receipt << left << setw(28) << "Firstname: " << store_fnames[get_id-1] << endl;
					f_receipt << left << setw(28) << "Middlename: " << store_mnames[get_id-1] << endl;
					f_receipt << "-------------------------------------------" << endl;
					f_receipt << left << setw(28) << "Rate per day: " << "P250" << endl;
					f_receipt << left << setw(28) << "Enter Working Days: " << setw(28) << working_days << endl;
					f_receipt << left << setw(28) << "Grosspay: " << total << endl;
					f_receipt << "-------------------------------------------" << endl;
					f_receipt << left << setw(28) << "Cash Advance: " << cash_advance << endl;
					f_receipt << left << setw(28) << "SSS: " << "130" << endl;
					f_receipt << left << setw(28) << "Phil Health: " << "160" << endl;
					f_receipt << left << setw(28) << "Pagibig: " << "150" << endl;
					f_receipt << left << setw(28) << "Others: " << others << endl;
					f_receipt << left << setw(28) << "Deductions: " << deduct << endl;
					f_receipt << "-------------------------------------------" << endl;
					f_receipt << left << setw(28) << "Netpay: " << total - deduct << endl;
					f_receipt << "-------------------------------------------" << endl << endl;
					
					f_receipt.close();
					system("Receipt.txt");
					
				}
				cout << "[1] Home" << endl;
				cout << "[2] Back" << endl;
				cout << "[3] Exit" << endl;
				cout << "Choice: ";
				cin >> choice2;
				while(choice2 != '1' && choice2 != '2' && choice2 != '3')
				{
					cout << "Invalid Input! Please enter the correct choice!" << endl;
					cout << "Choice: ";
					cin >> choice2;
				}
				switch (choice2)
				{
					case '1': system("cls"); main(); break;
					case '2': system("cls"); goto payroll; break;
					case '3': system("pause"); exit(0); break;
				}
			}
		}
		show_id.close(); show_lname.close(); show_fname.close(); show_mname.close();
	}
	if(toupper(salary_choice) == 'N')
	{
		char choice3;
		cout << "[1] Home" << endl;
		cout << "[2] Back" << endl;
		cout << "[3] Exit" << endl;
		cout << "Choice: ";
		cin >> choice3;
		while(choice3 != '1' && choice3 != '2')
		{
			cout << "Invalid Input!" << endl;
			cout << "Please enter the correct choice!" << endl;
			cout << "Choice: ";
			cin >> choice3;
		}
		switch (choice3)
		{
			case '1': system("cls"); main(); break;
			case '2': system("pause"); exit(0); break;
		}
	}
}

void delete_employee()
{
	int id, get_id, x=0, temp_id,k=0;
	int delete_id;
	string lname, fname, mname, lnames, fnames, mnames;
	string store_lnames[60], store_fnames[60], store_mnames[60];
	char salary_choice;
	
	ifstream show_id("ID.txt");
	ifstream show_lname("Lastname.txt");
	ifstream show_fname("Firstname.txt");
	ifstream show_mname("Middlename.txt");
	
	cout << "List of Employee:" << endl;
	cout << "\tID Number\t\tLastname\t\tFirstname\t\tMiddlename" << endl;
	while(show_id >> id && getline(show_lname,lname) && getline(show_fname, fname) && getline(show_mname, mname))
	{
		cout << left <<"\t   " << setw(21) << id << setw(24)  << lname << setw(24)  << fname  << mname << endl;
		k++;
	}
	show_id.close(); show_lname.close(); show_fname.close(); show_mname.close();
	if(k==0)
	{
		cout << endl << endl << "No Records Listed" << endl;
		char choice4;
		cout << "[1] Home" << endl;
		cout << "[2] Exit" << endl;
		cout << "Choice: ";
		cin >> choice4;
		while(choice4 != '1' && choice4 != '2')
		{
			cout << "Invalid Input!" << endl;
			cout << "Please enter the correct choice!" << endl;
			cout << "Choice: ";
			cin >> choice4;
		}
		switch (choice4)
		{
			case '1': system("cls"); main(); break;
			case '2': system("pause"); exit(0); break;
		}
	}
	cout << "Enter the ID number of the employee you want to delete? ";
	cin >> delete_id;
	
	int id1;
	string lname1, fname1, mname1;
	ifstream delete_id1("ID.txt");
	ifstream delete_lname("Lastname.txt");
	ifstream delete_fname("Firstname.txt");
	ifstream delete_mname("Middlename.txt");
	
	ofstream temp1("temp1.txt", ios::out | ios::app);
	ofstream temp2("temp2.txt", ios::out | ios::app);
	ofstream temp3("temp3.txt", ios::out | ios::app);
	ofstream temp4("temp4.txt", ios::out | ios::app);
	
	while(delete_id1 >> id1 && getline(delete_lname,lname1) && getline(delete_fname, fname1) && getline(delete_mname, mname1))
	{
		if(delete_id != id1)
		{
			temp1 << id1 << endl;
			temp2 << lname1 << endl;
			temp3 << fname1 << endl; 
			temp4 << mname1 << endl;
		}
	}
	temp1.close(); temp2.close(); temp3.close(); temp4.close();
	delete_id1.close();  delete_lname.close(); delete_fname.close(); delete_mname.close();
	
		
	remove("ID.txt");
	remove("Lastname.txt");
	remove("Firstname.txt");
	remove("Middlename.txt");
	rename("temp1.txt", "ID.txt");
	rename("temp2.txt", "Lastname.txt");
	rename("temp3.txt", "Firstname.txt");
	rename("temp4.txt", "Middlename.txt");
	
	char d_choice;
	cout << "Records Sucessfully Deleted!" << endl;
	cout << "[1] Home" << endl;
	cout << "[2] Exit" << endl;
	cout << "Choice: ";
	cin >> d_choice;
	switch(d_choice)
	{
		case '1': system("cls"); main(); break;
		case '2': system("pause"); exit(0); break;
	}
}



