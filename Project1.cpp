#include <iostream>
#include <ctime>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    void setuserName(string username)
    {
        this->username = username;
    }
    string getuserName()
    {
        return username;
    }
    void setPassword(string password)
    {
        this->password = password;
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
    void setCustomerName(string customerName)
    {
        this->customerName = customerName;
    }
    string getCustomerName()
    {
        return customerName;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    string getAddress()
    {
        return address;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    string getEmail()
    {
        return email;
    }
    void setContactNo(string contactNo)
    {
        this->contactNo = contactNo;
    }
    string getContactNo()
    {
        return contactNo;
    }
    void setGender(string gender)
    {
        this->gender = gender;
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
    void Register(int customerId)
    {
        this->customerId = customerId;
        cout << "\nEnter Name: ";
        cin >> customerName;
        cout << "\nEnter UserName: ";
        cin >> _userName;
        setuserName(_userName);
        cout << "\nEnter Password: ";
        cin >> _password1;
        setPassword(_password1);
        cout << "\nEnter Addaress: ";
        cin >> address;
        cout << "\nEnter Email: ";
        cin >> email;
        do
        {
            cout << "\nEnter Contact Number: ";
            cin >> _contactNo;
            if (_contactNo.length() == 10)
            {
                contactNo = _contactNo;
                _contactNo = "";
                break;
            }
            else
            {
                contactNo = "";
                cout << "\nEntered Contact Number is Not Valid!! Please Try Again!!" << endl;
            }
        } while (1);

        do
        {
            int n;
            cout << "\nEnter Gender: 1.Male\t2.Femail";
            cout << "\nEnter related number here:  ";
            cin >> n;
            if (n == 1)
            {
                gender = "male";
                break;
            }
            else if (n == 2)
            {
                gender = "Femail";
                break;
            }
            else
            {
                cout << "\nYour entered is invalid. Please enter Again!!" << endl;
            }

        } while (1);
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

        cout << "\nEnter the Number Do you want to change: ";
        cin >> n;

        if (n == 1)
        {
            cout << "\nEnter the New Name: ";
            cin >> customerName;
        }
        else if (n == 2)
        {
            cout << "\nEnter the New UserName: ";
            cin >> _userName;
            setuserName(_userName);
        }
        else if (n == 3)
        {
            cout << "\nEnter the New Address: ";
            cin >> address;
        }
        else if (n == 4)
        {
            cout << "\nEnter the new Email: ";
            cin >> email;
        }
        else if (n == 5)
        {
            do
            {
                cout << "\nEnter the new Contact Number: ";
                cin >> _contactNo;
                if (_contactNo.length() == 10)
                {
                    contactNo = _contactNo;
                    _contactNo = "";
                    break;
                }
                else
                {
                    contactNo = "";
                    cout << "\nEntered Contact Number is Not Valid!!" << endl;
                }
            } while (1);
        }
        else if (n == 6)
        {
            do
            {
                cout << "\nGender: 1.Male\t2.Femail" << endl;
                cout << "Enter related number here: " << endl;
                cin >> n;

                if (n == 1)
                {
                    gender = "Male";
                    break;
                }
                else if (n == 2)
                {
                    gender = "Femail";
                    break;
                }
                else
                {
                    cout << "\nYour entered is Invalid!! Please Try Again!!" << endl;
                }
            } while (1);
        }
        else if (n == 7)
        {
            do
            {
                cout << "\nEnter the new password: ";
                cin >> _password1;
                cout << "Enter the password again: ";
                cin >> _password2;
                if (_password1 == _password2)
                {
                    setPassword(_password1);
                    cout << "\nPassword Change Updated!!" << endl;
                    _password1 = "";
                    _password2 = "";
                    break;
                }
                else
                {
                    cout << "\nYour entered is Not Match. Try Again!!" << endl;
                }
            } while (1);
        }
        else
        {
            cout << "Your Entered is Invalid!! Please Try Again!!" << endl;
            n = 20;
        }
        if (n < 10)
        {
            cout << "\nYour Update is Successfull!!" << endl;
        }
    }
};

//Created Customer Object Array as globally
Customer objArray[20];

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
    int RemoveCustomer(int NumberOfCustomers)
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
            indexOf_n = -1;

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
                cout << "*********************************************" << endl;
                for (int i = indexOf_n; i < NumberOfCustomers; i++)
                {
                    objArray[i] = objArray[i + 1];
                }
                NumberOfCustomers--;
                cout << "\nCustomer Removed!!" << endl;
            }
        }
        else
        {
            cout << "\nErorr!!" << endl;
        }
        return NumberOfCustomers;
    }
};

class Item
{
private:
    int productID;
    string productName;
    string description;
    int price;
    int amount;
    int discount;
    //string details;

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
    int getAmount()
    {
        return amount;
    }
    int getProductDiscount()
    {
        return discount;
    }
    void addItem(int numberOfItem)
    {
        int n;
        productID = numberOfItem; //first item productId is 1
        cout << "\nEnter Product Name: ";
        cin >> productName;
        cout << "Enter Description: ";
        cin >> description;
        cout << "Enter the Price: ";
        cin >> price;
        cout << "Enter the Amount of Product: ";
        cin >> amount;
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
        cout << "\n********************************************" << endl;
        cout << "Select Item Details" << endl;
        cout << "\nItem ID: " << productID << endl;
        cout << "1.Item Name: " << productName << endl;
        cout << "2.Item description: " << description << endl;
        cout << "3.Item Price: " << price << endl;
        cout << "4.Item Amount: " << amount << endl;
        cout << "5.Item  discount: ";
        if (discount == 0)
        {
            cout << "Not discount!!" << endl;
        }
        else
        {
            cout << discount << endl;
        }

        cout << "\nEnter the Number Do you want to change: ";
        cin >> n;

        if (n == 1)
        {
            cout << "\nEnter the new Item name: ";
            cin >> productName;
        }
        else if (n == 2)
        {
            cout << "\nEnter the new description: ";
            cin >> description;
        }
        else if (n == 3)
        {
            cout << "\nEnter the new Price: ";
            cin >> price;
        }
        else if (n == 4)
        {
            cout << "\nEnter the new Amount: ";
            cin >> amount;
        }

        else if (n == 5)
        {
            cout << "\nEnter the new discountL: ";
            cin >> discount;
        }
        else
        {
            cout << "\nYour Entered is Invalid!!" << endl;
            n = -1;
        }
        if (n != -1)
        {
            cout << "\nYour Update is Successfull!!" << endl;
        }
    }
    void viewProducts()
    {
        cout << "\n********************************************" << endl;
        cout << "\nItem ID: " << productID << endl;
        cout << "1.Item Name: " << productName << endl;
        cout << "2.Item description: " << description << endl;
        cout << "3.Item Price: " << price << endl;
        cout << "4.Item Amount: " << amount << endl;
        cout << "5.Item  discount: ";
        if (discount == 0)
        {
            cout << "\nNot discount!!" << endl;
        }
        else
        {
            cout << discount << endl;
        }
    }
    void restocked()
    {
        //nothing implement yet
    }
};
//Created Item Object Array as globally
Item itemArray[20];

class Order
{
private:
    int orderId;
    int shoppingCartId;
    string date;
    //string customerName;    *customerId included shopping cart. shopping cart id is existing here.
    //string customerId;        therefore we can findout customer details throught that path.
    bool status;
    //bool orderStatus;

public:
    Order() {} //Declared Order type object array below this class.
    //default constructor should be include so that create the below object array
    Order(int shoppingCartId)
    {
        status = false;

        this->shoppingCartId = shoppingCartId;
        // time_t now = time(0);
        // tm *ltm = localtime(&now);
    }
    int getShoppingCartId()
    {
        return shoppingCartId;
    }
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
        status = true;
    }
    void cancelOrder()
    {
        status = false;
    }
};

Order orderArray[20];

class ShoppingCart
{
private:
    int cartId;
    int customerId;
    int productId[10];
    int quantity[10];
    int priceOfitem[10];
    int numberOfItemsInCart = 0;
    int totalPrice = 0;
    int _quantity;

public:
    ShoppingCart() {} //default constructor
    ShoppingCart(int customerId, int cartId)
    {
        this->customerId = customerId;
        this->cartId = cartId;
    }
    int getCustomerId()
    {
        return customerId;
    }
    void PrintMethod()
    {
        cout << "\n****************************************" << endl;
        cout << "\tCustomer ID: " << customerId << endl;
        cout << "\tCart ID: " << cartId << endl;
        for (int i = 0; i < numberOfItemsInCart; i++)
        {
            cout << "\n\tProduct ID: " << productId[i] << endl;
            cout << "\tQuantity: " << quantity[i] << endl;
            cout << "\tPrice: " << priceOfitem[i] << endl;
        }
        cout << "\n\tTotal Price: " << totalPrice << endl;
        cout << "\n****************************************" << endl;
    }
    int addCard(int numberOfItem, int numberOfOrder)
    {
        totalPrice = 0;
        int n;
        do
        {
            cout << "\n**************************************************************" << endl;
            cout << "\n\t  Product ID\t\tProduct Name" << endl;
            for (int i = 0; i < numberOfItem; i++)
            {
                cout << "\t\t" << itemArray[i].getProductID() << "\t\t  " << itemArray[i].getProductName() << endl;
            }
            cout << "\n**************************************************************" << endl;

            cout << "\nEnter the item number which you want: ";
            cin >> n;
            productId[numberOfItemsInCart] = n;

            cout << "\nYou enter item is: " << itemArray[n - 1].getProductName() << endl;
            cout << "Price: " << itemArray[n - 1].getProductPrice() << endl;

            cout << "\nEnter the Item amount: ";
            cin >> _quantity;

            quantity[numberOfItemsInCart] = _quantity;

            priceOfitem[numberOfItemsInCart] = quantity[numberOfItemsInCart] * itemArray[n - 1].getProductPrice();

            totalPrice = totalPrice + priceOfitem[numberOfItemsInCart];

            cout << "\nPrice: " << priceOfitem[numberOfItemsInCart] << "/=" << endl;
            cout << "\nIf you want to continue, press any number otherwise you want to exit press '0' : ";
            cin >> n;
            numberOfItemsInCart++;
        } while (n != 0);

        cout << "\nTotal Price: " << totalPrice << "/=" << endl;

        cout << "\nDo you want add this cart to order?" << endl;
        cout << "1.Yes\t2.No" << endl;
        cout << "\nEnter your option: ";
        cin >> n;

        if (n == 1)
        {
            orderArray[numberOfOrder] = Order(cartId);
            numberOfOrder++;
            cout << "\nCart Added Successfull.!!" << endl;
        }
        return numberOfOrder;
    }
};
ShoppingCart shoppingCartArray[20]; //this array start index is number 1

int selectIndexOfItem(int numberOfItem)
{
    int indexOfselectItem;
    cout << "\n************************************************" << endl;
    cout << "NumberOfItems: " << numberOfItem << endl;
    cout << "\n\t Product ID\t Product Name" << endl;

    for (int i = 0; i < numberOfItem; i++)
    {
        cout << "\t\t" << itemArray[i].getProductID() << "\t    " << itemArray[i].getProductName() << endl;
    }

    do
    {
        cout << "\nEnter the ProductID do you want to update or view: ";
        cin >> indexOfselectItem;

        indexOfselectItem--;

        if (indexOfselectItem < numberOfItem)
        {
            break;
        }
        else
        {
            cout << "\nYour entered has some issues. Please Try Again!!" << endl;
        }

    } while (1);

    return indexOfselectItem;
}

void printOrder(int indexOfOrder)
{
    int cartId = orderArray[indexOfOrder].getShoppingCartId();
    int customerId = shoppingCartArray[cartId - 1].getCustomerId();
    cout << "\nCustomer Name: " << objArray[customerId - 1].getCustomerName() << endl;
    shoppingCartArray[cartId - 1].PrintMethod();
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
    int numberOfShoppingCart = 1;
    int numberOfOrder = 0;
    do
    {
        cout << "\n1.Customer     \t2.Administrator\t   3.Exit" << endl;
        cout << "Select Your Choice: ";
        cin >> n;
        if (n != 3 && n < 3)
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
                    cout << "\n1.Edit Customer Details\t   2.Transactions\t 3.LogOut" << endl;
                    cout << "Enter Your choice: ";
                    cin >> n;

                    if (n == 1)
                    {
                        objArray[indexOfCurrentCustomer].updateProfile();
                    }
                    else if (n == 2)
                    {
                        shoppingCartArray[numberOfShoppingCart - 1] = ShoppingCart(objArray[indexOfCurrentCustomer].getCustomerId(), numberOfShoppingCart);

                        cout << "\n1.Add Cart\t  2.Delete Cart\t  3.Update Quantity\t   4.View Cart\t  5.View Item Details" << endl;
                        cout << "Enter Your choice: ";
                        cin >> n;

                        if (n == 1)
                        {
                            if (numberOfItem == 0)
                            {
                                cout << "\nNothing Any Item Yet" << endl;
                                cout << numberOfItem << endl;
                            }
                            else
                            {
                                numberOfOrder = shoppingCartArray[numberOfShoppingCart - 1].addCard(numberOfItem, numberOfOrder);
                            }
                        }
                        else if (n == 2)
                        {
                            /* code */
                        }
                        else if (n == 3)
                        {
                            /* code */
                        }
                        else if (n == 4)
                        {
                            /* code */
                        }
                        else if (n == 5)
                        {
                            /* code */
                        }
                        else
                        {
                            cout << "\nYou entered is invalid.!!" << endl;
                        }

                        numberOfShoppingCart++;
                    }
                    else if (n == 3)
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
                cout << "\nYour Login Succussfull!!" << endl;
                do
                {
                    cout << "\n1.Add Customer\t   2.Remove Customer\t3.Item \t   4.LogOut\t5.AddCart\t6.View Order" << endl;
                    cout << "Enter Your Option: ";
                    cin >> n;
                    if (n == 1)
                    {
                        NumberOfCustomers = admin.AddCustomer(NumberOfCustomers);
                        cout << "\nItem Added Successefull!!" << endl;
                    }
                    else if (n == 2)
                    {
                        NumberOfCustomers = admin.RemoveCustomer(NumberOfCustomers);
                    }
                    else if (n == 3)
                    {
                        do
                        {
                            cout << "\n1.Add Item\t2.Update Item\t  3.View Item\t4.Exit" << endl;
                            cout << "Enter your option: ";
                            cin >> n;
                            if (n == 1)
                            {
                                itemArray[indexOfItem].addItem(indexOfItem + 1); //indexOfitem and numberOfitem are
                                indexOfItem++;                                   // By default zero
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
                                    itemArray[indexOfselectItem].updateItem();
                                }
                            }
                            else if (n == 3)
                            {
                                if (numberOfItem == 0)
                                {
                                    cout << "\nNothing any item yet" << endl;
                                }
                                else
                                {
                                    indexOfselectItem = selectIndexOfItem(numberOfItem);
                                    itemArray[indexOfselectItem].viewProducts();
                                }
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
                    else if (n == 4)
                    {
                        break;
                    }
                    else if (n == 5)
                    {
                        // ShoppingCart sc(1, 1);
                        // sc.addCard(numberOfItem);
                    }
                    else if (n == 6)
                    {
                        cout << "\n**************************************************" << endl;
                        cout << "Number Of Order: " << numberOfOrder << endl;
                        cout << "*************** Order Details *****************" << endl;
                        cout << "\n1.View 1st Order\t2.View all Order\t3.Exit" << endl;
                        cout << "Enter your option: ";
                        cin >> n;
                        if (n == 1)
                        {
                            printOrder(0);
                        }
                        else if (n == 2)
                        {
                            for (int i = 0; i < numberOfOrder; i++)
                            {
                                printOrder(i);
                            }
                        }
                        else if (n == 3)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "\nYour Entered is Incorrect.!!" << endl;
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

    return 0;
}
