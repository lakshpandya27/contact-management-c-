#include<iostream>
#include<string>
using namespace std;


#define Max 1000 



struct Contacts
{
	string cName;		
	int cGender = 1;	
	int cAge = 0;		
	string cPhone;		
	string cAdd;		
};


struct AddressBooks
{
	Contacts contactsArry[Max];	
	int aCount = 0;				
};


void showMenu()
{
	cout << "******************************************" << endl;
	cout << "***** Notification management system *****" << endl;
	cout << "******************************************" << endl;
	cout << "*****    1、Add a contact            *****" << endl;
	cout << "*****    2、Contacts are displayed     *****" << endl;
	cout << "*****    3、Delete the contact         *****" << endl;
	cout << "*****    4、Find a contact             *****" << endl;
	cout << "*****    5、Modify the contact         *****" << endl;
	cout << "*****    6、Clear your contacts        *****" << endl;
	cout << "*****    0、Exit the address book      *****" << endl;
	cout << "********************************" << endl;
	cout << "***********Version1.0***********" << endl;
	cout << "********************************" << endl;
}


void AddContacts(AddressBooks* abs)
{
	
	if (abs->aCount == Max)
	{
		cout << "The address book is full and can't be added！" << endl;
		return;
	}
	else
	{
		
		string name;
		cout << "Please enter a name： " << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		//性别
		int gender;
		cout << "Please enter your gender： " << endl;
		cout << "1 Male " << endl;
		cout << "2 Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << "Please re-enter if you made a mistake！" << endl;
		}

		
		int age;
		cout << "Please enter your age： " << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;

		
		string phone;
		cout << "Please enter a phone number： " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		
		string add;
		cout << "Please enter an address： " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		
		abs->aCount += 1;
		cout << "Added successfully！" << endl;
		system("pause");
		
		system("cls");
	}

}


void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "If you don't have a contact, please add it first!" << endl;
	}
	else
	{
		
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << "Name：" << abs->contactsArry[i].cName << "Gender：" << (abs->contactsArry[i].cGender != 2 ? "Male" : "Female") << " Age：" << abs->contactsArry[i].cAge << "Phone：" << abs->contactsArry[i].cPhone << " Address：" << abs->contactsArry[i].cAdd << endl;
		}
	}
	system("pause");
	system("cls");
}


int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}


void DeleteContacts(AddressBooks* abs)
{
	
	string name;
	cout << "Please enter the name of the user you want to delete：" << endl;
	cin >> name;
	
	int index = IsExit(abs, name);

	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		
		abs->aCount--;
		cout << "The deletion is successful！" << endl;
	}
	else
	{
		cout << "No such person was found" << endl;
	}
	system("pause");
	system("cls");
}

void GetContacts(AddressBooks* abs)
{
	
	string name;
	cout << "Please enter the name of the user you are looking for" << endl;
	cin >> name;
	
	int index = IsExit(abs, name);
	if (index > -1)
	{
	
		cout << "Name：" << abs->contactsArry[index].cName << endl;
		cout << "Gender：" << abs->contactsArry[index].cGender << endl;
		cout << "Age：" << abs->contactsArry[index].cAge << endl;
		cout << "Phone：" << abs->contactsArry[index].cPhone << endl;
		cout << "Address：" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		
		cout << "No such person was found" << endl;
	}
	system("pause");
	system("cls");

}


void ModefyContacts(AddressBooks* abs)
{
	
	string name;
	cout << "Please enter the name of the user you want to edit" << endl;
	cin >> name;
	
	int index = IsExit(abs, name);
	if (index > -1)
	{
		
		string name;
		cout << "Please enter your revised name： " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

	
		int gender;
		cout << "Please enter the modified gender： " << endl;
		cout << "1 Male " << endl;
		cout << "2 Female  " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << "If you have made a mistake, please re-enter！" << endl;
		}

	
		int age;
		cout << "Please enter the revised age： " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		
		string phone;
		cout << "Please enter the revised phone number： " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

	
		string add;
		cout << "Please enter the revised address： " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << "Modification successful!" << endl;
	}
	else
	{
		
		cout << "No such person was found" << endl;
	}
	system("pause");
	system("cls");
}


void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << "Are you sure you want to empty your contacts? (Y confirmed/N cancelled)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "If you have made a mistake, please re-enter!!" << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << "Cleared successfully!!" << endl;
	}
	else
	{
		cout << "The operation has been canceled!!" << endl;
	}
	system("pause");
	system("cls");
}


int main()
{
	
	int select = 0;

	AddressBooks abs;
	
	abs.aCount = 0;

	while (true)
	{
		
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:
			AddContacts(&abs);	
			break;
		case 2:
			ShowContacts(&abs); 
			break;
		case 3:
			DeleteContacts(&abs);
			break;
		case 4:
			GetContacts(&abs);
			break;
		case 5:
			ModefyContacts(&abs);
			break;
		case 6:
			ClearContacts(&abs);
			break;
		case 0:
			cout << "See you next time！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");//按任意键继续
	return 0;
}
