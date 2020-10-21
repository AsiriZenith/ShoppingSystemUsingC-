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
        cout << "Enter Name: ";
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
};
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
        //NumberOfCustomers++;
        return ++NumberOfCustomers;
    }
    void RemoveCustomer(int NumberOfCustomers)
    {
        int n;
        cout << "************************************************" << endl;
        cout << "\n Customer ID\tCustomer Name" << endl;
        for (int i = 0; i < NumberOfCustomers; i++)
        {
            cout << "\t" << objArray[i].getCustomerId() << "\t    " << objArray[i].getCustomerName() << endl;
        }
        cout << "Enter the CustomerId which you want to Remove: ";
        cin >> n;
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

// bool login()
// {
//     string username, password;
//     cout << "Enter Your Username: ";
//     cin >> username;
//     cout << "Enter Your Password: ";
//     cin >> password;

//     return admin.login(username, password);
// }

// void RemoveCustomer(int NumberOfCustomers)
// {
//     int n;
//     cout << "************************************************" << endl;
//     cout << "\n Customer ID\tCustomer Name" << endl;
//     for (int i = 0; i < NumberOfCustomers; i++)
//     {
//         cout << "\t" << objArray[i].getCustomerId() << "\t    " << objArray[i].getCustomerName() << endl;
//     }
//     cout << "Enter the CustomerId which you want to Remove: ";
//     cin >> n;
// }

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
    do
    {
        cout << "\n1.Customer\t2.Administrator\t    3.Exit" << endl;
        cout << "Select Your Choice: ";
        cin >> n;
        if (n == 1)
        {
            do
            {
                cout << "1.Login\t2.LogOut" << endl;
                cout << "Select Your Option: ";
                cin >> n;

                if (n == 1)
                {
                    //user.Login(objArray, NumberOfCustomers);
                }
                else if (n == 2)
                {
                    break;
                }
                else
                {
                    cout << "Your Entered is Inavalid!! Try Again.." << endl;
                }
            } while (1);
        }
        else if (n == 2)
        {
            cout << "\nEnter Your Username: ";
            cin >> username;
            cout << "Enter Your Password: ";
            cin >> password;

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
                        cout << "**********************************" << endl;
                        cout << NumberOfCustomers << endl;
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
            cout << "Your Entered is Incorrect.!!" << endl;
        }
    } while (1);
}