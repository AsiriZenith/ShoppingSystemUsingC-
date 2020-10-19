#include <iostream>
using namespace std;

class User
{
public:
    string username;
    string password;
    // User objArray1[10];
public:
    bool Login(User objectArray[], int NumberOfCustomers)
    {
        cout << "Enter Your Username: ";
        cin >> username;
        if (username == objectArray[0].username)
        {
            cout << "Enter Your Password: ";
            cin >> password;
            if (password == objectArray[0].password)
            {
                cout << "***********" << endl;
                cout << objectArray[0].password << endl;
                return true;
            }
            else
            {
                cout << "Passowrd Is Incorrect. Try Again.!!"<<endl;
                return false;
            }
        }
        else
        {
            cout << "There is no such user. Please Try Again.!!" << endl;
            return false;
        }
        return 0;
    }
};

class Administrator : public User
{
public:
    string adminName;
    //string password;

public:
    // void setAdminName(string a)
    // {
    //     adminName = a;
    // }
    // string getAdminName()
    // {
    //     return adminName;
    // }
    // void setPassword(string p)
    // {
    //     password = p;
    // }
};

class Customer : public User
{
private:
    //int customerId;
    string customerName;
    string address;
    string email;
    string contactNo;
    string gender;
    // int paymentDetails;
    // string orderDeatils;

public:
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
    void Register()
    {
        cout << "Enter Your Name: ";
        cin >> customerName;
        cout << "Enter UserName: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Your Addaress: ";
        cin >> address;
        cout << "Enter Your Email: ";
        cin >> email;
        cout << "Enter Your Contact Number: ";
        cin >> contactNo;
        cout << "Enter Your Gender: ";
        cin >> gender;
    }
};

int main()
{
    Customer objArray1[10];
    User user;
    Administrator admin;
    admin.adminName = "admin";
    admin.password = "admin@123";
    admin.username = "admin";
    Administrator admin1[1];
    int NumberOfCustomers = 0;
    int n;
    cout << "1.Customer\t2.Administrator" << endl;
    cout << "Select Your Role: ";
    cin >> n;
    if (n == 1)
    {
        do
        {
            cout << "1.Login\t  2.Register\t3.LogOut" << endl;
            cout << "Select Your Option: ";
            cin >> n;

            if (n == 1)
            {
                //user.Login(objArray1, NumberOfCustomers);
            }
            else if (n == 2)
            {
                objArray1[NumberOfCustomers].Register();
                NumberOfCustomers++;
            }
            else if (n == 3)
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
        do
        {
            cout << "1.Login\t  2.LogOut" << endl;
            cout << "Select Your Option: ";
            cin >> n;
            if (n == 1)
            {
                admin1[0] = admin;
                if (user.Login(admin1, 1))
                {
                    cout << "$$$$$$$$$$$$$$" << endl;
                }
                else
                {
                    cout << "Not Login!!" << endl;
                }
            }
            else if (n == 2)
            {
                break;
            }
            else
            {
                cout << "Your Entered is Invalid.!!" << endl;
            }

        } while (1);
    }

    else
    {
        /* code */
    }
}