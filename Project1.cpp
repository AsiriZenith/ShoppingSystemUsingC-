#include <iostream>
using namespace std;

class User
{
public:
    string username;
    string password;

public:
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
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Addaress: ";
        cin >> address;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Contact Number: ";
        cin >> contactNo;
        cout << "Enter Gender: ";
        cin >> gender;
    }
    void updateProfile(int indexOfCustomer)
    {
        cout << "\n*******************************************" << endl;
        cout << "Current customer details" << endl;

        cout << "\nCustomer Name: ";
        cout << objArray[indexOfCurrentCustomer].getCustomerName() << endl;
        cout << "Customer UserName: ";
        cout << objArray[indexOfCurrentCustomer].username << endl;
        cout << "Customer Address: ";
        cout << objArray[indexOfCurrentCustomer].getAddress() << endl;
    }
};

//Created Customer Object Array as globally
Customer objArray[10];

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

int main()
{
    User user;
    Administrator admin;
    admin.adminName = "admin";
    admin.password = "admin@123";
    admin.username = "admin";
    Administrator admin1[1];
    int NumberOfCustomers = 0;
    string username, password;
    int n;
    bool IsLogged;
    int indexOfCurrentCustomer = 0;
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
                    cout << "\nNothing Such User" << endl;
                    IsLogged = false;
                }
            }
            if (IsLogged)
            {
                do
                {
                    cout << "\n1.Edit Customer Details\t2.LogOut" << endl;
                    cout << "Enter Your choice: ";
                    cin >> n;
                    if (n == 1)
                    {
                        objArray[indexOfCurrentCustomer].updateProfile(indexOfCurrentCustomer);
                        // cout << "\n*******************************************" << endl;
                        // cout << "Current customer details" << endl;

                        // cout << "\nCustomer Name: ";
                        // cout << objArray[indexOfCurrentCustomer].getCustomerName() << endl;
                        // cout << "Customer UserName: ";
                        // cout << objArray[indexOfCurrentCustomer].username << endl;
                        // cout << "Customer Address: ";
                        // cout << objArray[indexOfCurrentCustomer].getAddress() << endl;
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
            // cout << "\nEnter Your Username: ";
            // cin >> username;
            // cout << "Enter Your Password: ";
            // cin >> password;

            if (admin.login(username, password))
            {
                do
                {
                    cout << "\n1.Add Customer\t  2.Remove Customer\t3.LogOut" << endl;
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