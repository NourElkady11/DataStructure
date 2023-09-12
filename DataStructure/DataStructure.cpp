#include<stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class product
{
public:
	int id; int stock; int price; string name;
	product* pnext;
	product()
	{
		id = 0;
		stock = 0;
		price = 0;
		name = ' ';
	}

};
class customer
{
public:
	int id; string name; int pass;
	customer* pnext;
};
class shop
{
public:
	int pid;  int cid;
	shop* pnext;

	shop()
	{
		pnext = NULL;
	}

};
class admin
{
public:
	int id; string name; int pass;
	admin* pnext;
	admin()
	{
		pnext = NULL;
		id = 0;
		name = ' ';
		pass = 0;
	}
};
class clist1               //product
{
public:
	product* phead;
	product* ptail;

	clist1()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist1()
	{
		product* pnn;
		pnn = phead;
		while (phead != NULL)
		{
			phead = phead->pnext;
			delete pnn;
			pnn = phead;
		}
	}
	void attach(product* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;

		}
	}
	void display()
	{
		product* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->id << " ";
			cout << ptrav->name << " ";
			cout << ptrav->price << " ";
			cout << ptrav->stock << " ";
			ptrav = ptrav->pnext;
			cout << endl;
		}
	}
	void remove(int v)
	{
		product* ptrav = phead;
		product* pb = NULL;
		while (ptrav != NULL && ptrav->id != v)
		{
			pb = ptrav;
			ptrav = ptrav->pnext;
		}
		if (pb != NULL)
		{
			pb->pnext = ptrav->pnext;
			if (ptrav == ptail)
			{
				pb->pnext = NULL;
				ptail = pb;
			}
		}
		else
		{
			phead = ptrav->pnext;
		}
		delete ptrav;
	}

};
class clist2    // customer 
{
public:
	customer* phead;
	customer* ptail;

	clist2()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist2()
	{
		customer* pnn;
		pnn = phead;
		while (phead != NULL)
		{
			phead = phead->pnext;
			delete pnn;
			pnn = phead;
		}


	}

	void attach(customer* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;

		}
	}
	void display()
	{
		customer* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->id << " ";
			cout << ptrav->name << " ";
			cout << ptrav->pass << " ";
			cout << endl;
			ptrav = ptrav->pnext;
		}
	}


};
class clist3       //shop
{
public:
	shop* phead;
	shop* ptail;

	clist3()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist3()
	{
		shop* pnn;
		pnn = phead;
		while (phead != NULL)
		{
			phead = phead->pnext;
			delete pnn;
			pnn = phead;
		}

	}

	void attach(shop*& pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;

		}
	}
	void display()
	{
		shop* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->pid << " ";
			cout << ptrav->cid << " ";
			cout << endl;
			ptrav = ptrav->pnext;
		}
	}

};
class clist4       //admin
{
public:
	admin* phead;
	admin* ptail;

	clist4()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist4()
	{
		admin* pnn;
		pnn = phead;
		while (phead != NULL)
		{
			phead = phead->pnext;
			delete pnn;
			pnn = phead;
		}


	}

	void attach(admin* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;

		}
	}
	void display()
	{
		admin* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->id << " ";
			cout << ptrav->name << " ";
			cout << ptrav->pass << " ";
			cout << endl;
			ptrav = ptrav->pnext;
		}
	}


};
void main()
{
	clist1 l1;
	clist2 l2;
	clist3 l3;
	clist4 l4;
	product* pnnp = NULL;
	customer* pnnc = NULL;
	shop* pnns = NULL;
	admin* pnna = NULL;
	product* pnni = NULL;
	fstream profile;
	fstream custfile;
	fstream shopfile;
	fstream adminfile;
	int k, v, z, t, edeny, pr, hm, s, g, f, val;
	int tot = 0;
	int ct = 0;
	string n, q, l;
	profile.open("C:\\Users\\Actel\\Desktop\\product.txt");  //product
	if (profile.is_open())
	{
		string p;
		while (getline(profile, p))
		{
			string temp1[4]; int t = 0;
			for (int i = 0; i < p.length(); i++)
			{
				if (p[i] == ',')
				{
					t++;
				}
				else
				{
					temp1[t] += p[i];
				}

			}
			pnnp = new product;
			pnnp->id = stoi(temp1[0]);
			pnnp->name = temp1[1];
			pnnp->price = stoi(temp1[2]);
			pnnp->stock = stoi(temp1[3]);
			s = pnnp->id + 1;
			l1.attach(pnnp);
		}
	}
	profile.close();
	custfile.open("C:\\Users\\Actel\\Desktop\\custmor.txt");    //customer
	if (custfile.is_open())
	{
		string c;
		while (getline(custfile, c))
		{
			string temp2[3]; int t = 0;
			for (int i = 0; i < c.length(); i++)
			{
				if (c[i] == ',')
				{
					t++;
				}
				else
				{
					temp2[t] += c[i];
				}

			}
			pnnc = new customer;
			pnnc->id = stoi(temp2[0]);
			pnnc->name = temp2[1];
			pnnc->pass = stoi(temp2[2]);
			l2.attach(pnnc);
			val = pnnc->id + 1;
		}
	}
	custfile.close();
	shopfile.open("C:\\Users\\Actel\\Desktop\\shop.txt");       //shop
	if (shopfile.is_open())
	{
		string s;
		while (getline(shopfile, s))
		{
			string temp3[2]; int t = 0;
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == ',')
				{
					t++;
				}
				else
				{
					temp3[t] += s[i];
				}

			}
			pnns = new shop;
			pnns->pid = stoi(temp3[0]);
			pnns->cid = stoi(temp3[1]);
			l3.attach(pnns);
		}
	}
	shopfile.close();
	adminfile.open("C:\\Users\\Actel\\Desktop\\admin.txt");       //admin
	if (adminfile.is_open())
	{
		string a;
		while (getline(adminfile, a))
		{
			string temp4[3]; int t = 0;
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] == ',')
				{
					t++;
				}
				else
				{
					temp4[t] += a[i];
				}
			}
			pnna = new admin;
			pnna->id = stoi(temp4[0]);
			pnna->name = temp4[1];
			pnna->pass = stoi(temp4[2]);
			l4.attach(pnna);
		}
	}
	adminfile.close();
	cout << "Choose one from the following " << endl;
	cout << "---------------------------------" << endl;
	cout << "1- admin ?" << endl;
	cout << "2-Customer ?" << endl;
	cout << "3-Exit" << endl;
	cin >> k;
	if (k == 1)    //admin
	{

		cout << "press 1 to sign in ? " << endl;
		//cout << "2-Display all products"<<endl;
		//cout << "3-Adjust any product"<<endl;
		//cout << "4-Delete any product"<<endl;
		//cout << "5-Add new product" << endl;
		//cout << "6-Display all products that the stock is less than a specific quantity"<<endl;
		//cout << "7-Display how many orders are done by specific customer"<<endl;
		//cout << "8-Log out"<<endl;
		cin >> v;
		if (v == 1)
		{
			cout << "Write your name ? ";
			cin >> n;
			cout << "Enter your password ? ";
			cin >> t;
			pnna = l4.phead;
			while (pnna != NULL)
			{
				if (n == pnna->name && t == pnna->pass)
				{
					cout << "Login successfully" << endl;
					cout << endl;
					cout << "what do you want to do ?" << endl;
					cout << "---------------------------------" << endl;
					cout << "1-Display all products" << endl;
					cout << "2-Adjust any product" << endl;
					cout << "3-Delete any product" << endl;
					cout << "4-Add new product" << endl;
					cout << "5-Display all products that the stock is less than a specific quantity" << endl;
					cout << "6-Display how many orders are done by specific customer" << endl;
					cout << "7-Log out" << endl;
					cin >> edeny;
					if (edeny == 1)
					{
						l1.display();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;
					}
					if (edeny == 2)
					{
						cout << "Enter the id of the product you want to adjust ";
						cin >> k;
						pnnp = l1.phead;
						while (pnnp != NULL)
						{
							if (pnnp->id == k)
							{
								f = 1;
								break;
							}
							else
							{
								f = 0;
							}
							pnnp = pnnp->pnext;
						}
						if (f == 0)
						{
							cout << "This product dosent even exist" << endl;
						}
						if (f == 1)
						{
							cout << "Enter your new price ";
							cin >> pr;
							cout << "Enter the new stock number ";
							cin >> g;
							cout << endl;
							pnnp = l1.phead;
							while (pnnp != NULL)
							{
								if (pnnp->id == k)
								{
									pnnp->price = pr;
									pnnp->stock = g;
								}
								pnnp = pnnp->pnext;
							}

							l1.display();

						}
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;
					}
					if (edeny == 3)
					{
						cout << "What is the id of the product you want to delete" << endl;
						cin >> t;
						cout << endl;
						l1.remove(t);
						l1.display();
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;
					}
					if (edeny == 4)
					{
						cout << "what is the name of the product you want to add ? " << endl;
						cin >> l;
						cout << "Enter price to this product ? " << endl;
						cin >> pr;
						cout << "How much do you have to this product ? " << endl;
						cin >> hm;
						pnnp = new product;
						pnnp->id = s;
						pnnp->name = l;
						pnnp->price = pr;
						pnnp->stock = hm;
						l1.attach(pnnp);
						l1.display();
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;

					}
					if (edeny == 5)
					{
						cout << "Display the specfic quantity ?" << endl;
						cin >> g;
						cout << endl;
						pnnp = l1.phead;
						int min = 999;
						while (pnnp != NULL)
						{
							if (pnnp->stock < min)
							{
								min = pnnp->stock;
							}
							pnnp = pnnp->pnext;
						}
						pnnp = l1.phead;
						if (g > min)
						{
							while (pnnp != NULL)
							{
								if (pnnp->stock < g)
								{
									cout << pnnp->name << endl;
								}
								pnnp = pnnp->pnext;
							}
							cout << endl;
						}
						else
						{
							cout << "No product less than this quantity" << endl;
						}
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;
					}

					if (edeny == 6)
					{
						cout << "Enter the id of the customer ? ";
						cin >> t;
						cout << endl;
						pnns = l3.phead;
						while (pnns != NULL)
						{
							if (pnns->cid == t)
							{
								ct++;
							}
							pnns = pnns->pnext;
						}

						cout << "this customer made " << ct << " orders " << endl;
						cout << endl;
						cout << "what do you want to do ?" << endl;
						cout << "---------------------------------" << endl;
						cout << "1-Display all products" << endl;
						cout << "2-Adjust any product" << endl;
						cout << "3-Delete any product" << endl;
						cout << "4-Add new product" << endl;
						cout << "5-Display all products that the stock is less than a specific quantity" << endl;
						cout << "6-Display how many orders are done by specific customer" << endl;
						cout << "7-Log out" << endl;
						cin >> edeny;
					}
					if (edeny == 7)
					{

					}

					pnna = pnna->pnext;
				}
				else
				{

					cout << "You are not admin " << endl;
					break;
				}
			}


		}
		else
		{
			cout << "Please press 1 to sign in";
		}
	}
	if (k == 2)      //cutomer 
	{
		cout << "Choose one from the following " << endl;
		cout << "---------------------------------" << endl;
		cout << "1-Login " << endl;
		cout << "2-Register" << endl;
		cout << "5-Log out" << endl;
		cin >> z;
		if (z == 1)
		{
			cout << endl;
			cout << "Enter your name ? ";
			cin >> n;
			cout << "Enter your password ? ";
			cin >> t;
			cout << endl;
			pnnc = l2.phead;
			int flag = 0;
			while (pnnc != NULL)
			{
				if (pnnc->name == n && pnnc->pass == t)
				{
					flag = 1;
					cout << "what do you want to do ?" << endl;
					cout << "---------------------------------" << endl;
					cout << "1-Buy product" << endl;
					cout << "2-return product" << endl;
					cout << "3- Exit" << endl;
					cin >> edeny;
					if (edeny == 1)
					{
						cout << "Enter your id  ";
						cin >> k;
						pnns = new shop;
						pnns->cid = k;
						pnns->pid = 372;
						l3.attach(pnns);
						pnnp = l1.phead;
						l3.display();
						while (pnnp != NULL)
						{
							if (pnnp->stock > 0)
							{
								cout << pnnp->name << endl;
							}
							pnnp = pnnp->pnext;
						}
						int fl = 0;
						int fso = 0;
						while (fl == 0)
						{
							cout << "what do you want to buy ? " << endl;
							cout << "---------------------------------" << endl;
							cin >> n;
							pnnp = l1.phead;
							while (pnnp != NULL)
							{
								if (pnnp->name == n)
								{
									fso = 1;
									pnnp->stock--;
									cout << pnnp->name << "    "; cout << pnnp->price << endl;
									tot += pnnp->price;

								}

								pnnp = pnnp->pnext;
							}
							if (fso == 0)
							{
								cout << "This product dosent exist ? <<" << endl;
							}
							cout << endl;
							cout << "Do you want to buy anything else ? " << endl;
							cin >> l;
							if (l == "yes")
							{
								fl = 0;
							}
							else
							{
								cout << "your total 7esab is  " << tot << "L.E" << endl;
								break;
							}

						}

					}
					if (edeny == 2)
					{
						//return product
						cout << "Enter the name of the product you want to return: ";
						cin >> n;
						pnnp = l1.phead;
						int sos = 0;
						while (pnnp != NULL)
						{
							if (pnnp->name == n)
							{
								sos = 1;
								pnnp->stock++;
							}
							pnnp = pnnp->pnext;
						}
						if (sos == 0)
						{
							cout << "This product wasnt exist in our product" << endl;
						}
					}
					if (edeny == 3)
					{
						//exit
					}

				}
				pnnc = pnnc->pnext;
			}
			if (flag == 0)
			{
				cout << "your acount is not found if you want to register press 2 on the next time" << endl;
			}
		}
		if (z == 2)
		{
			cout << "Enter you name: ";
			cin >> l;
			cout << "Enter your password: ";
			cin >> t;
			pnnc = new customer;
			pnnc->id = val;
			pnnc->name = l;
			pnnc->pass = t;
			l2.attach(pnnc);
			l2.display();



		}
	}
	if (k == 3)
	{

	}
	profile.open("C:\\Users\\Actel\\Desktop\\product.txt", ios::in | ios::out | ios::trunc);
	pnnp = l1.phead;
	while (pnnp != NULL)
	{
		profile << pnnp->id << "," << pnnp->name << "," << pnnp->price << "," << pnnp->stock << endl;
		pnnp = pnnp->pnext;
	}
	profile.close();
	custfile.open("C:\\Users\\Actel\\Desktop\\custmor.txt", ios::in | ios::out | ios::trunc);
	pnnc = l2.phead;
	while (pnnc != NULL)
	{
		custfile << pnnc->id << "," << pnnc->name << "," << pnnc->pass << endl;
		pnnc = pnnc->pnext;
	}
	custfile.close();
	shopfile.open("C:\\Users\\Actel\\Desktop\\shop.txt", ios::in | ios::out | ios::trunc);
	pnns = l3.phead;
	while (pnns != NULL)
	{
		shopfile << pnns->pid << "," << pnns->cid << endl;
		pnns = pnns->pnext;
	}
	shopfile.close();
	adminfile.open("C:\\Users\\Actel\\Desktop\\admin.txt", ios::in | ios::out | ios::trunc);
	pnna = l4.phead;
	while (pnna != NULL)
	{
		adminfile << pnna->id << "," << pnna->name << "," << pnna->pass << endl;
		pnna = pnna->pnext;
	}
	adminfile.close();


}