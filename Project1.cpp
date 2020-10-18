#include <iostream>
using namespace std;

class User
{
public:
    string username;
    string password;
    // User objArray1[10];
public:
    // User(User s[], int size)
    // {
    //     //objArray1[10]=s[size];
    //     cout << s[0].username;
    // }
    // void setUserName(string u)
    // {
    //     username = u;
    // }
    // string getUserName()
    // {
    //     return username;
    // }
    // string getPassword()
    // {
    //     return password;
    // }
    void Login(User objectArray[])
    {
        // cout << "Enter Username: ";
        // cin >> username;
        cout << objectArray[0].username << endl;
    }
};

class Administrator : public User
{
private:
    string adminName;
    string password;

public:
    void setAdminName(string a)
    {
        adminName = a;
    }
    string getAdminName()
    {
        return adminName;
    }
    void setPassword(string p)
    {
        password = p;
    }
};

class Customer : public User
{
private:
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
    Customer objArray[10];
    User user;
    int NumberOfCustomers = 0;
    int n;
    cout << "Select Your Role:" << endl;
    cout << "1.Customer\t2.Administrator" << endl;
    cin >> n;
    if (n == 1)
    {
        do
        {
            cout << "1.Login\t  2.Register\t3.Exit" << endl;
            cout << "Select Your Option: " << endl;
            cin >> n;

            if (n == 1)
            {
                user.Login(objArray);
            }
            else if (n == 2)
            {
                objArray[NumberOfCustomers].Register();
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

        int _NumberOfCustomers = NumberOfCustomers;
        while (_NumberOfCustomers >= 0)
        {
            cout << objArray[_NumberOfCustomers].getCustomerName();
            cout << endl;
            cout << objArray[_NumberOfCustomers].getAddress();
            cout << endl;
            cout << objArray[_NumberOfCustomers].getContactNo();
            cout << endl;
            cout << objArray[_NumberOfCustomers].getEmail();
            cout << endl;
            cout << objArray[_NumberOfCustomers].getGender();
            cout << endl;
            _NumberOfCustomers--;
        }
    }
    else
    {
        /* code */
    }
}