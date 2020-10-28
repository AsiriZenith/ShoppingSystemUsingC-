#include <iostream>
using namespace std;

class User
{
private:
    string username;
    string password;

public:
    void setuserName(string u)
    {
        username = u;
    } 
    string getuserName()
    {
        return username;
    }
    void setPassword(string s)
    {
        password = s;
    }
    bool login(string un, string pwd)
    {
        if ((un.compare(username) == 0) && (pwd.compare(password) == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Customer : public User
{
private:
    int customerId;
    string customerName;
    string address;
    string email;
    string contactNo;
    string gender;
    string _contactNo;
    string _password1;
    string _password2;
    string _userName;
    // int paymentDetails;
    // string orderDeatils;

public:
    int getCustomerId()
    {
        return customerId;
    }
    void setCustomerName(string s)
    {
        customerName = s;
    }
    string getCustomerName()
    {
        return customerName;
    }
    void setAddress(string a)
    {
        address = a;
    }
    string getAddress()
    {
        return address;
    }
    void setEmail(string e)
    {
        email = e;
    }
    string getEmail()
    {
        return email;
    }
    void setContactNo(string c)
    {
        contactNo = c;
    }
    string getContactNo()
    {
        return contactNo;
    }
    void setGender(string g)
    {
        gender = g;
    }
    string getGender()
    {
        return gender;
    }
    // void setPaymentDetails(string p)
    // {
    //     paymentDetails = p;
    // }
    // int getPaymentDetails()
    // {
    //     return paymentDetails;
    // }
    // void setOrderDeatils(string o)
    // {
    //     orderDeatils = o;
    // }
    // string getOrderDeatils()
    // {
    //     return orderDeatils;
    // }
    void Register(int id)
    {
        customerId = id;
        cout << "\nEnter Name: ";
        cin >> customerName;
        cout << "Enter UserName: ";
        cin >> _userName;
        setuserName(_userName);
        cout << "Enter Password: ";
        cin >> _password1;
        setPassword(_password1);
        cout << "Enter Addaress: ";
        cin >> address;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Contact Number: ";
        cin >> _contactNo;
        if (_contactNo.length() == 10)
        {
            contactNo = _contactNo;
            _contactNo = "";
        }
        else
        {
            contactNo = "";
            cout << "Entered Contact Number is Not Valid!!" << endl;
        }
        cout << "Enter Gender: ";
        cin >> gender;
    }
    void updateProfile()
    {
        int n;
        cout << "\n*******************************************" << endl;
        cout << "Current customer details" << endl;

        cout << "\nCustomer ID: ";
        cout << getCustomerId() << endl;
        cout << "1.Customer Name: ";
        cout << getCustomerName() << endl;
        cout << "2.Customer UserName: ";
        cout << getuserName() << endl;
        cout << "3.Customer Address: ";
        cout << getAddress() << endl;
        cout << "4.Customer Email: ";
        cout << getEmail() << endl;
        cout << "5.Customer Contact Number: ";
        cout << getContactNo() << endl;
        cout << "6.Customer Gender: ";
        cout << getGender() << endl;
        cout << "7.Password: ";
        cout << "********" << endl;

        cout << "Enter the Number Do you want to change: ";
        cin >> n;

        if (n == 1)
        {
            cout << "Enter the New Name: ";
            cin >> customerName;
        }
        else if (n == 2)
        {
            cout << "Enter the New UserName: ";
            cin >> _userName;
            setuserName(_userName);
        }
        else if (n == 3)
        {
            cout << "Enter the New Address: ";
            cin >> address;
        }
        else if (n == 4)
        {
            cout << "Enter the new Email: ";
            cin >> email;
        }
        else if (n == 5)
        {
            cout << "Enter the new Contact Number: ";
            cin >> _contactNo;
            if (_contactNo.length() == 10)
            {
                contactNo = _contactNo;
                _contactNo = "";
            }
            else
            {
                contactNo = "";
                cout << "Entered Contact Number is Not Valid!!" << endl;
            }
        }
        else if (n == 6)
        {
            cout << "Enter gender: ";
            cin >> gender;
        }
        else if (n == 7)
        {
            cout << "Enter the new password: ";
            cin >> _password1;
            cout << "Enter the password again: ";
            cin >> _password2;
            if (_password1 == _password2)
            {
                setPassword(_password1);
                cout << "Password Change Updated!!" << endl;
                _password1 = "";
                _password2 = "";
            }
            else
            {
                cout << "Your entered is Not Match. Try Again!!" << endl;
            }
        }
        else
        {
            cout << "Your Entered is Invalid!!" << endl;
        }
    }
};

//Created Customer Object Array as globally
Customer objArray[1000000000000000];

class Administrator : public User
{
public:
    string adminName;
    string pasword;

public:
    int AddCustomer(int NumberOfCustomers)
    {
        objArray[NumberOfCustomers].Register(NumberOfCustomers + 1);
        return ++NumberOfCustomers;
    }
    void RemoveCustomer(int NumberOfCustomers)
    {
        int n, indexOf_n;
        cout << "************************************************" << endl;
        cout << "NumberOfCustomers: " << NumberOfCustomers << endl;
        cout << "\n Customer ID\tCustomer Name" << endl;
        for (int i = 0; i < NumberOfCustomers; i++)
        {
            cout << "\t" << objArray[i].getCustomerId() << "\t    " << objArray[i].getCustomerName() << endl;
        }

        if (NumberOfCustomers == 0)
        {
            cout << "Nothing Customers in the list!!" << endl;
        }
        else if (NumberOfCustomers > 0)
        {
            cout << "Enter the CustomerId which you want to Remove: ";
            cin >> n;

            for (int i = 0; i < NumberOfCustomers; i++)
            {
                if (objArray[i].getCustomerId() == n)
                {
                    indexOf_n = i;
                    break;
                }
                else if (objArray[i].getCustomerId() != n && i + 1 == NumberOfCustomers)
                {
                    cout << "Nothing Such Customers here!!" << endl;
                    indexOf_n = -1;
                }
            }
            if (indexOf_n != -1)
            {
                for (int i = indexOf_n; i < NumberOfCustomers; i++)
                {
                    objArray[i] = objArray[i + 1];
                }
            }
        }
        else
        {
            cout << "\nErorr!!" << endl;
        }
    }
};

class Item
{
private:
    int productID;
    string productName;
    string description;
    int price;
    int discount;

public:
    int getProductID()
    {
        return productID;
    }
    string getProductName()
    {
        return productName;
    }
    string getProductDscription()
    {
        return description;
    }
    int getProductPrice()
    {
        return price;
    }
    int getProductDiscount()
    {
        return discount;
    }
    void addItem(int numberOfItem)
    {
        int n;
        productID = numberOfItem;
        cout << "\nEnter Product Name: ";
        cin >> productName;
        cout << "Enter Description: ";
        cin >> description;
        cout << "Enter the Price: ";
        cin >> price;
        cout << "Have a Discount this product: " << endl;
        cout << "1.Yes\t2.No" << endl;
        cout << "Enter the Number: ";
        cin >> n;
        if (n == 1)
        {
            cout << "Enter the Discount: ";
            cin >> discount;
        }
        else if (n == 2)
        {
            discount = 0;
        }

        {
            cout << "Your Entered is Invalid!!" << endl;
        }
        cout << "\nItem Added Succussful!!" << endl;
    }
    void updateItem()
    {
        int n;
    }
};

//Created Item Object Array as globally
Item itemArray[20];

class Order
{
private:
    int orderId;
    string date;
    string customerName;
    string customerId;
    bool status;
    bool orderStatus;

public:
    bool checkStatus()
    {
        if (status == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void confirmOrder()
    {
        orderStatus = true;
    }
    void cancelOrder()
    {
        orderStatus = false;
    }
};

int selectIndexOfItem(int numberOfItem)
{
    int indexOfselectItem;
    cout << "\n************************************************" << endl;
    cout << "NumberOfItems: " << numberOfItem << endl;
    cout << "\n Item ID\t Item Name" << endl;

    for (int i = 0; i < numberOfItem; i++)
    {
        cout << "\t" << itemArray[i].getProductID() << "\t    " << itemArray[i].getProductName() << endl;
    }

    cout << "Enter the ProductID do you want to update: ";
    cin >> indexOfselectItem;
    return indexOfselectItem;
}

int main()
{
    User user;
    Administrator admin;
    admin.adminName = "admin";
    admin.setuserName("admin");
    admin.setPassword("admin@123");
    Administrator admin1[1];
    int NumberOfCustomers = 0;
    string username, password;
    int n;
    bool IsLogged;
    int indexOfCurrentCustomer = 0;
    int indexOfItem = 0;
    int numberOfItem = 0;
    int indexOfselectItem;
    do
    {
        cout << "\n1.Customer\t2.Administrator\t    3.Exit" << endl;
        cout << "Select Your Choice: ";
        cin >> n;
        if (n != 3)
        {
            cout << "\nEnter Your Username: ";
            cin >> username;
            cout << "Enter Your Password: ";
            cin >> password;
        }

        if (n == 1)
        {
            for (int i = 0; i < NumberOfCustomers; i++)
            {
                if (objArray[i].login(username, password))
                {
                    cout << "\nYour Login Succussful!!" << endl;
                    IsLogged = true;
                    indexOfCurrentCustomer = i;
                    break;
                }
                else if (i == NumberOfCustomers - 1)
                {
                    cout << "\nYour Entered is Invalid!!" << endl;
                    IsLogged = false;
                }
            }
            if (IsLogged)
            {
                do
                {
                    cout << "\n1.Edit Customer Details\t  2.LogOut" << endl;
                    cout << "Enter Your choice: ";
                    cin >> n;
                    if (n == 1)
                    {
                        objArray[indexOfCurrentCustomer].updateProfile();
                    }
                    else if (n == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\nYour Enterd is Invalid!!" << endl;
                    }
                } while (1);
            }
        }
        else if (n == 2)
        {
            if (admin.login(username, password))
            {
                do
                {
                    cout << "\n1.Add Customer\t  2.Remove Customer\t3.Add Item  \t4.LogOut" << endl;
                    cout << "Enter Your Option: ";
                    cin >> n;
                    if (n == 1)
                    {
                        NumberOfCustomers = admin.AddCustomer(NumberOfCustomers);
                    }
                    else if (n == 2)
                    {
                        admin.RemoveCustomer(NumberOfCustomers);
                        NumberOfCustomers--;
                    }
                    else if (n == 3)
                    {
                        do
                        {
                            cout << "\n1.Add Item\t2.Update Item\t3.View Item\t4.Exit" << endl;
                            cout << "Enter your option: ";
                            cin >> n;
                            if (n == 1)
                            {
                                itemArray[indexOfItem].addItem(indexOfItem + 1);
                                indexOfItem++;
                                numberOfItem = indexOfItem;
                            }
                            else if (n == 2)
                            {
                                if (numberOfItem == 0)
                                {
                                    cout << "\nNothing any item yet" << endl;
                                }
                                else
                                {
                                    indexOfselectItem = selectIndexOfItem(numberOfItem);
                                }
                            }
                            else if (n == 3)
                            {
                                /* code */
                            }
                            else if (n == 4)
                            {
                                break;
                            }

                        } while (1);
                    }
                    else if (n == 4)
                    {
                        break;
                    }

                    else
                    {
                        cout << "Your Entered is Incorrect.!!" << endl;
                    }

                } while (1);
            }
            else
            {
                cout << "Your Username Or Password is Incorrect.!!" << endl;
            }
        }
        else if (n == 3)
        {
            break;
        }

        else
        {
            cout << "\nYour Entered is Incorrect.!!" << endl;
        }
    } while (1);
}