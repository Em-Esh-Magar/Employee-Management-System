// Employee Management System

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<fstream>

using namespace std;

class Heading{
	public:
		void getheading()
		{
			cout << "\n\t\t\t\t\t\t\t*****************************************************\n";
    		cout << "\t\t\t\t\t\t\t=====================================================\n";
    		cout << "\t\t\t\t\t\t\t||                                                 ||\n";
    		cout << "\t\t\t\t\t\t\t||           ----------------------------          ||\n";
    		cout << "\t\t\t\t\t\t\t||            Employee Management System           ||\n";
    		cout << "\t\t\t\t\t\t\t||           ----------------------------          ||\n";
    		cout << "\t\t\t\t\t\t\t||                                                 ||\n";
    		cout << "\t\t\t\t\t\t\t=====================================================\n";
    		cout << "\t\t\t\t\t\t\t*****************************************************\n\n\n";
		}
		
};

class Employee : public Heading{
	protected:
		char emp_name[30];
		char emp_address[30];
		int emp_id;
		char emp_department[30];
		unsigned long long int emp_phno;
		char emp_position[20];
		float emp_salary;
		
	public:
		void getempdata()
		{
			cout<<endl;
			cout<<"\n\t\t\t\t\t\t\t\t    ***** Enter your data *****";
			cout<<"\n\n\t\t\t\t\t\t\t Name           : ";
			fflush(stdin);
			cin.get(emp_name,30);
			cout<<"\n\t\t\t\t\t\t\t Address        : ";
			fflush(stdin);
			cin.get(emp_address,30);
			cout<<"\n\t\t\t\t\t\t\t Id             : ";
			cin>>emp_id;
			cout<<"\n\t\t\t\t\t\t\t Department     : ";
			fflush(stdin);
			cin.get(emp_department,30);
			cout<<"\n\t\t\t\t\t\t\t Phone Number   : ";
			cin>>emp_phno;
			cout<<"\n\t\t\t\t\t\t\t Position       : ";
			fflush(stdin);
			cin.get(emp_position,30);
			cout<<"\n\t\t\t\t\t\t\t Salary         : ";
			cin>>emp_salary;	
		}
		
		int getid()
		{
			return emp_id;
		}
		
		void display_emp_data()
		{
			cout<<"\n\t\t\t\t\t\t\t Name           : "<<emp_name;
			cout<<"\n\t\t\t\t\t\t\t Address        : "<<emp_address;
			cout<<"\n\t\t\t\t\t\t\t Id             : "<<emp_id;
			cout<<"\n\t\t\t\t\t\t\t Department     : "<<emp_department;
			cout<<"\n\t\t\t\t\t\t\t Phone Number   : "<<emp_phno;
			cout<<"\n\t\t\t\t\t\t\t Position       : "<<emp_position;
			cout<<"\n\t\t\t\t\t\t\t Salary         : "<<emp_salary;
		}
	
};


void Login();
void Signup();
void Forget();

int menu()
{
	int x;
	Heading head;
	head.getheading();
	cout<<"\n\n\t\t\t\t\t\t\t 1. Login";
	cout<<"\n\n\t\t\t\t\t\t\t 2. Signup";
	cout<<"\n\n\t\t\t\t\t\t\t 3. Forget password";
	cout<<"\n\n\t\t\t\t\t\t\t 4. Exit";
	cout<<"\n\n\t\t\t\t\t\t Enter your choice : ";
	cin>>x;
	return x;
}

int main()
{
	while(1){
		system("cls");
		int login_choice;
		login_choice=menu();
		switch(login_choice)
		{
			case 1:
			{
				Login();
			}
			break;
			case 2:
			{
				Signup();
			}
			break;
			case 3:
			{
				Forget();
				cout<<"\to be set";
			}
			break;
			case 4:
			{
				exit(0);
			}
			break;
			default:
			cout<<"\n\n\t\t\t\t\t\t Out of service. Try again.";
			getch();
		}
	}
	return 0;
}

void Signup()
{
	again:
	Heading obj;
	system("cls");
	obj.getheading();
	fstream signup_data;
	string username, password;
	cout<<"\n\n\t\t\t\t\t\t Username : ";
	cin>>username;
	cout<<"\n\n\t\t\t\t\t\t Password : ";
	cin>>password;
	
	signup_data.open("Login_Data.dat",ios::out | ios::app);
	if(signup_data.fail())
	{
		cout<<"\n\n\t\t\t\t\t\t File Doesn't exit.";
		cout<<"\n\n\t\t\t\t\t\t Try again.";
		goto again;
	}
	signup_data<<username<<' '<<password<<endl;
	cout<<"\n\n\t\t\t\t\t\t Signup successfully.";
	cout<<"\n\n\t\t\t\t\t\t Press any key.";
	getch();
}

void Login()
{
	again:
	Heading obj;
	system("cls");
	obj.getheading();
	fstream login_file;
	string login_user, login_pass;
	string file_user, file_pass;
	cout<<"\n\n\t\t\t\t\t\t Username : ";
	cin>>login_user;
	cout<<"\n\n\t\t\t\t\t\t Password : ";
	cin>>login_pass;
	int don=0;
	login_file.open("Login_Data.dat",ios::in);
	while(login_file>>file_user>>file_pass)
	{
		int check1, check2;
		if(file_user==login_user){
			if(file_pass==login_pass)
			{
				don=1;
				break;
			}
		}
		
	}
	login_file.close();
	if(don==0)
	{
		cout<<"\n\n\t\t\t\t\t\t Username and Password Doesn't Matched. Try again.";
		getch();
		goto again;
	}
	else{
		
		cout<<"\n\n\t\t\t\t\t\t Welcome to EMPLOYEE MANAGEMENT SYSTEM......."<<endl;
		getch();
		Program:
		int choice;
		char x;
		while(1){
			system("cls");
			Heading show_title;
			Employee employee_data;
			show_title.getheading();
			cout<<"\n\n\t\t\t\t\t\t\t\t 1. Create Employee Record";
			cout<<"\n\t\t\t\t\t\t\t\t 2. Display Employee Record";
			cout<<"\n\t\t\t\t\t\t\t\t 3. Modify Employee Record";
			cout<<"\n\t\t\t\t\t\t\t\t 4. Search Employee Record";
			cout<<"\n\t\t\t\t\t\t\t\t 5. Delete Employee Record";
			cout<<"\n\t\t\t\t\t\t\t\t 6. Exit";
			cout<<"\n\n\t\t\t\t\t\t\t\t Enter your choice : ";
			cin>>choice;
	
			switch(choice)
			{
				case 1:
				{
					fstream save_data;
					save_data.open("Employee_Management_system.dat",ios::out|ios::app|ios::binary );
					do{
						system("cls");
						employee_data.getheading();
						employee_data.getempdata();
						//employee_add_data();
						save_data.write((char *)&employee_data , sizeof(employee_data));
						cout<<"\n\t\t\t\t\t\t\t Do you want to create record again. Press Y for again and else for no.";
						cout<<"\n\t\t\t\t\t\t\t Your choice : ";
						cin>>x;
					}while(x=='Y' || x=='y');
					save_data.close();
				}
				break;
				
				case 2:
				{	
					system("cls");
					show_title.getheading();
					int i=1;
					fstream read_data;
					read_data.open("Employee_Management_system.dat",ios::in | ios::binary);
					if(read_data.fail())
					{
						cout<<"\n\t\t\t\t\t\t\t File Doesn't exit";
					}
					Employee read_object;
					while( read_data.read((char *)&read_object , sizeof(read_object)) )
					{
						cout<<"\n\t\t\t\t\t\t\t ****Record no. "<<i<<"***";
						read_object.display_emp_data();
						i++;
						cout<<endl;
					}
					read_data.close();
					cout<<"\n\t\t\t\t\t\t\t\t Press any key to continue.";
					getch();
				}
				break;
			
				case 3:
				{
					system("cls");
					show_title.getheading();
					int flag=0, id=0, cur=0;
					cout<<"\n\t\t\t\t\t\t\t\t For Modification. Enter your id : ";
					cin>>id;
					Employee modify_data;
					fstream modify_file;
					modify_file.open("Employee_Management_system.dat",ios::in | ios::binary | ios::out);
					if(modify_file.fail())
					{
						cout<<"\n\t\t\t\t\t\t\t\t File Doesn't Exit.";
					}
					while( modify_file.read((char *)&modify_data , sizeof(modify_data)) )
					{
						cur = modify_file.tellg();
						if(id==modify_data.getid())
						{
							modify_data.display_emp_data();
							cout<<"\n\t\t\t\t\t\t\t\t Enter your new data : ";
							modify_data.getempdata();
							modify_file.seekg(cur-sizeof(modify_data));
							modify_file.write((char *)&modify_data , sizeof(modify_data));
							flag++;
							cout<<"\n\n\t\t\t\t\t\t\t\t\t Data Has Been Updated.";
							cout<<"\n\t\t\t\t\t\t\t\t\t Press any key to continue.";
							getch();
						}
					}
					if(flag==0)
					{
						cout<<"\n\t\t\t\t\t\t\t\t Id doesn't Matched.";
						getch();
					}
					modify_file.close();
				}
				break;
				
				case 4:
				{	
					system("cls");
					show_title.getheading();
					int search_id=0, flag=0;
					Employee search_data;
					fstream search_file;
					search_file.open("Employee_Management_system.dat",ios::in | ios::binary);
					if(search_file.fail())
					{
						cout<<"\n\t\t\t\t\t\t\t\t File Doesn't Exit.";
					}
					cout<<"\n\t\t\t\t\t\t\t\t Enter your Id : ";
					cin>>search_id;
					while( search_file.read((char *)&search_data , sizeof(search_data)) )
					{
						if(search_id==search_data.getid())
						{
							cout<<"\n\t\t\t\t\t\t\t\t Your Id has been matched. ";
							search_data.display_emp_data();
							flag++;
							cout<<"\n\n\t\t\t\t\t\t\t\t Press any key to continue.";
							getch();
						}
					}
					if(flag==0)
					{
						cout<<"\n\n\t\t\t\t\t\t\t\t Id doesn't Matched.";
						cout<<"\n\t\t\t\t\t\t\t\t Press any key to continue.";
						getch();
					}
					search_file.close();
				}
				break;
				
				case 5:
				{
					system("cls");
					show_title.getheading();
					int delete_id;
					Employee delete_data;
					fstream Indata, Pushdata;
					Indata.open("Employee_Management_system.dat",ios::in);
					if(Indata.fail())
					{
						cout<<"\n\t\t\t\t\t\t\t\t File doesn't found.";	
						getch();
					}
					cout<<"\n\n\t\t\t\t\t\t\t\t Enter the id you want to delete : ";
					cin>>delete_id;
					Pushdata.open("New_data.dat",ios::out);
					while(Indata.read((char *)&delete_data , sizeof(delete_data)))
					{
						if(delete_id != delete_data.getid())
						{
							Pushdata.write((char *)&delete_data , sizeof(delete_data));
						}
						else
						{
							delete_data.display_emp_data();
							cout<<"\n\n\t\t\t\t\t\t\t\t This data has been deleted.";
							cout<<"\n\t\t\t\t\t\t\t\t Press any key to continue.";
							getch();
						}
					}
					Indata.close();
					Pushdata.close();
					remove("Employee_Management_system.dat");
					rename("New_data.dat","Employee_Management_system.dat");
				}
				break;	
			
				case 6:
					exit(0);
					
				default:
					cout<<"\n\n\t\t\t\t\t\t\t\t Out of services. Please Try again.";
					getch();
					goto Program;
			}
	
		}
	
	}
	getch();
}

void Forget()
{
	again:
	Heading obj;
	system("cls");
	obj.getheading();
	int data=0;
	string forget_username, forget_password, check_username;
	fstream forget_file;
	forget_file.open("Login_Data.dat",ios::in);
	if(forget_file.fail())
	{
		cout<<"\n\n\t\t\t\t\t\t File Doesn't exit.";
		cout<<"\n\n\t\t\t\t\t\t Try again.";
		goto again;
	}
	cout<<"\n\n\t\t\t\t\t\t Please provided username to search: ";
	cout<<"\n\n\t\t\t\t\t\t Username : ";
	cin>>check_username;
	while(forget_file>>forget_username>>forget_password)
	{
		if(check_username == forget_username)
		{
			data=1;
			cout<<"\n\n\t\t\t\t\t\t Your password is : "<<forget_password;
			cout<<"\n\n\t\t\t\t\t\t Press any key.";
			getch();
			break;
		}
	}
	forget_file.close();
	if(data==0)
	{
		cout<<"\n\n\t\t\t\t\t\t Cannot find your username. Please try again.";
		getch();
		goto again;
	}
	
}
