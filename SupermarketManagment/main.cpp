
#include <mysql.h>
#include <iostream>
#include <cstring>

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "bmeka1997";
char DB[] = "supermarketmgtdb";

struct product {
    int Product_ID;
    char Product_Name[50];
    char Product_Category[50];
    float Product_Price;
    int Product_QuantityInStock;
    int shelf_Order;
};

struct store {
    int store_ID;
    char store_Name[30];
    char store_Address[50];
    char store_phone[13];
    char store_managerName[25];
    char workingHour[10];
};

struct Employee {
    int employee_ID;
    char employee_FirstName[50];
    char employee_LastName[50];
    char contactNumber[15];
    char employee_position[25];
    char shift_schedule[14];
    float salary;
};

struct supplier {
    int supp_ID;
    char supp_name[25];
    char Address[50];
    char supp_phone[15];
    char supp_email[50];
};

struct customer {
    int customerID;
    char customerName[25];
    char customerAddress[50];
    char customerPhone[15];
    char customerEmail[50];
    float loyaltyPoint;
};

struct transaction {
    int transaction_ID;
    char transaction_date[11];  // Format YYYY-MM-DD
    char transaction_time[6];   // Format HH:MM
    int customer_ID;
    char product_Name[50];
    float total;
    char payment[20];
};

void accept(product pro[], int &n, MYSQL *conn) {
    cout << "Please record all products that you have" << endl;
    cout << "How many products are there?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the product id " << i + 1 << ": ";
        cin >> pro[i].Product_ID;
        cout << "Enter the product name: ";
        cin.ignore();
        cin.getline(pro[i].Product_Name, 50);
        cout << "Enter the product category: ";
        cin.getline(pro[i].Product_Category, 50);
        cout << "Enter the product price: ";
        cin >> pro[i].Product_Price;
        cout << "Enter the product quantity: ";
        cin >> pro[i].Product_QuantityInStock;
        cout << "Enter shelf number: ";
        cin >> pro[i].shelf_Order;

        // Prepare and execute SQL INSERT statement
        char query[512];
        snprintf(query, sizeof(query),
                 "INSERT INTO product (Product_ID, Product_Name, Product_Category, Product_Price, Product_QuantityInStock, shelf_Order) VALUES (%d, '%s', '%s', %f, %d, %d)",
                 pro[i].Product_ID, pro[i].Product_Name, pro[i].Product_Category, pro[i].Product_Price, pro[i].Product_QuantityInStock, pro[i].shelf_Order);
        if (mysql_query(conn, query)) {
            cerr << "Insert error: " << mysql_error(conn) << endl;
        } else {
            cout << "Product "<< pro[i].Product_Name<<" inserted successfully." << endl;
        }
    }
}

void Store(store st[], int &n, MYSQL *conn) {
    cout << "How many stores information do you want to add?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter store id: ";
        cin >> st[i].store_ID;
        cin.ignore();
        cout << "Enter name of the store: ";
        cin.getline(st[i].store_Name, 30);
        cout << "Enter store address: ";
        cin.getline(st[i].store_Address, 50);
        cout << "Enter phone number: ";
        cin.getline(st[i].store_phone, 13);
        cout << "Enter store manager name: ";
        cin.getline(st[i].store_managerName, 25);
        cout << "Enter working hours: ";
        cin.getline (st[i].workingHour,10);
        cin.ignore();

        // Prepare and execute SQL INSERT statement
        char query[512];
        snprintf(query, sizeof(query),
                 "INSERT INTO store (store_ID, store_Name, store_Address, store_phone, store_managerName, workingHour) VALUES (%d, '%s', '%s', '%s', '%s', '%s')",
                 st[i].store_ID, st[i].store_Name, st[i].store_Address, st[i].store_phone, st[i].store_managerName, st[i].workingHour);
        if (mysql_query(conn, query)) {
            cerr << "Insert error: " << mysql_error(conn) << endl;
        } else {
            cout << "Store_ID " << st[i].store_ID <<" inserted successfully." << endl;
        }
    }
}

void employee(Employee e[], int &n, MYSQL *conn) {
    cout << "How many employees do you want to  add? : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the ID of employee: ";
        cin >> e[i].employee_ID;
        cin.ignore();
        cout << "Enter employee first name: ";
        cin.getline(e[i].employee_FirstName, 50);
        cout<<"Enter employee last name: ";
        cin.getline(e[i].employee_LastName,50);
        cout<<"Enter employee phone number: ";
        cin.getline(e[i].contactNumber,15);
        cout << "Enter the position of the employee: ";
        cin.getline(e[i].employee_position, 25);
        cout << "Enter the shift schedule for employee (--:-- to --:--): ";
        cin.getline(e[i].shift_schedule, 14);
        cout<<"Enter employee salary: ";
        cin>>e[i].salary;
        cin.ignore();

        // Prepare and execute SQL INSERT statement
        char query[512];
        snprintf(query, sizeof(query),
                 "INSERT INTO Employee (employee_ID, employee_FirstName, employee_LastName, contactNumber, employee_position, shift_schedule, salary) VALUES (%d, '%s', '%s', '%s','%s','%s', %f)",
                 e[i].employee_ID, e[i].employee_FirstName,e[i].employee_LastName,e[i].contactNumber, e[i].employee_position, e[i].shift_schedule,e[i].salary);
        if (mysql_query(conn, query)) {
            cerr << "Insert error: " << mysql_error(conn) << endl;
        } else {
            cout << "Employee " << e[i].employee_FirstName  <<e[i].employee_LastName<<"inserted successfully." << endl;
        }
    }
}

void Supplier(supplier sp[], int &n, MYSQL *conn) {
    cout << "How many suppliers do you want to add?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter supplier ID: ";
        cin >> sp[i].supp_ID;
        cin.ignore();
        cout << "Enter the name of the supplier: ";
        cin.getline(sp[i].supp_name, 25);
        cout << "Enter the supplier address: ";
        cin.getline(sp[i].Address, 50);
        cout << "Enter the supplier phone number: ";
        cin.getline(sp[i].supp_phone,15);
        cout << "Enter the supplier's email address: ";
        cin.getline(sp[i].supp_email, 50);

        // Prepare and execute SQL INSERT statement
        char query[512];
        snprintf(query, sizeof(query),
                 "INSERT INTO supplier (supp_ID, supp_name, Address, supp_phone, supp_email) VALUES (%d, '%s', '%s', '%s', '%s')",
                 sp[i].supp_ID, sp[i].supp_name, sp[i].Address, sp[i].supp_phone, sp[i].supp_email);
        if (mysql_query(conn, query)) {
            cerr << "Insert error: " << mysql_error(conn) << endl;
        } else {
            cout << "Supplier " << sp[i].supp_name << " inserted successfully." << endl;
        }
    }
}

void Customer(customer cs[], int &n, MYSQL *conn) {
    char ch;
    float loyaltyPoint = 1;
    cout << "Are you a new customer? (y/n): ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
    	cout<<"How many customer inforamtion do you want to add?: ";
    	cin>>n;
        for (int i = 0; i < n; i++) {
            cout << "Enter customer id: ";
            cin >> cs[i].customerID;
            cin.ignore();
            cout << "Enter customer name: ";
            cin.getline(cs[i].customerName, 25);
            cout << "Enter customer address: ";
            cin.getline(cs[i].customerAddress, 50);
            cin.ignore();
            cout << "Enter phone number: ";
            cin.getline(cs[i].customerPhone, 15);
            cout << "Enter customer email: ";
            cin.getline(cs[i].customerEmail, 50);
            cs[i].loyaltyPoint = loyaltyPoint++;
            cout << "Your loyalty point is now " << cs[i].loyaltyPoint << endl;

            // Prepare and execute SQL INSERT statement
            char query[512];
            snprintf(query, sizeof(query),
                     "INSERT INTO customer (customerID, customerName, customerAddress, customerPhone, customerEmail, loyaltyPoint) VALUES (%d, '%s', '%s', '%s', '%s', %f)",
                     cs[i].customerID, cs[i].customerName, cs[i].customerAddress, cs[i].customerPhone, cs[i].customerEmail, cs[i].loyaltyPoint);
            if (mysql_query(conn, query)) {
                cerr << "Insert error: " << mysql_error(conn) << endl;
            } else {
                cout << "Customer " << cs[i].customerName << "inserted successfully." << endl;
            }
        }
    }
}

void Transaction(transaction tr[], int &n, MYSQL *conn) {
    cout << "How many transaction information  do you want to  add?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter transaction ID: ";
        cin >> tr[i].transaction_ID;
        cin.ignore();
        cout << "Enter transaction date (YYYY-MM-DD): ";
        cin.getline(tr[i].transaction_date, 11);
        cout << "Enter transaction time (HH:MM): ";
        cin.getline(tr[i].transaction_time, 6);
        cout << "Enter customer ID: ";
        cin >> tr[i].customer_ID;
        cin.ignore();
        cout << "Enter product name: ";
        cin.getline(tr[i].product_Name,50);
        cout << "Enter total amount: ";
        cin >> tr[i].total;
        cin.ignore();
        cout << "Enter payment method: ";
        cin.getline(tr[i].payment, 20);

        // Prepare and execute SQL INSERT statement
        char query[512];
        snprintf(query, sizeof(query),
                 "INSERT INTO transaction (transaction_ID, transaction_date, transaction_time, customer_ID, product_Name, total, payment) VALUES (%d, '%s', '%s', %d, '%s', %f, '%s')",
                 tr[i].transaction_ID, tr[i].transaction_date, tr[i].transaction_time, tr[i].customer_ID, tr[i].product_Name, tr[i].total, tr[i].payment);
        if (mysql_query(conn, query)) {
            cerr << "Insert error: " << mysql_error(conn) << endl;
        } else {
            cout << "Transaction " << tr[i].transaction_ID << " inserted successfully." << endl;
        }
    }
}
void display(product pro[],int &n,MYSQL *conn) {
    // SQL query to select all products
    const char *query = "SELECT Product_ID, Product_Name, Product_Category, Product_Price, Product_QuantityInStock, shelf_Order FROM product";

    // Execute the query
    if (mysql_query(conn, query)) {
        cerr << "Query execution error: " << mysql_error(conn) << endl;
        return;
    }

    // Store the result set
    MYSQL_RES *result = mysql_store_result(conn);
    if (!result) {
        cerr << "Error storing result: " << mysql_error(conn) << endl;
        return;
    }

    // Get the number of fields in the result set
    int num_fields = mysql_num_fields(result);

    // Get the field names
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++) {
        cout << fields[i].name << "\t\t";
    }
    cout << endl;

    // Fetch and print each row of the result set
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            cout << (row[i] ? row[i] : "NULL") << "\t\t\t";
        }
        cout << endl;
    }

    // Free the result set
    mysql_free_result(result);
}
void displayTransaction(transaction tr[],int &n,MYSQL *conn){
	const char *query = "SELECT transaction_ID,transaction_date,transaction_time, customer_ID,product_Name,total,payment FROM Transaction";
	if (mysql_query(conn, query)) {
        cerr << "Query execution error: " << mysql_error(conn) << endl;
        return;
    }
     MYSQL_RES *result = mysql_store_result(conn);
    if (!result) {
        cerr << "Error storing result: " << mysql_error(conn) << endl;
        return;
    }
  int num_fields = mysql_num_fields(result);
   MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++) {
        cout << fields[i].name << "\t\t";
    }
    cout << endl;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            cout << (row[i] ? row[i] : "NULL") << "\t\t";
        }
        cout << endl;
    }

    mysql_free_result(result);
}

void all_display(product pro[], store st[], customer cs[], supplier sp[], Employee e[], transaction tr[], int choice, int &n, MYSQL *conn) {
    switch (choice) {
        case 1: {
            int sub_choice;
            cout << "From product, what do you need?" << endl;
            cout << "1. To record all products we have" << endl;
            cout << "2. To display every information" << endl;
            cin >> sub_choice;
            if (sub_choice == 1) {
                accept(pro, n, conn);
            } else if (sub_choice == 2) {
                 display(pro, n,conn);
            } else {
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 2: {
                Store(st, n, conn);
            break;
        }
        case 3: {
        	int sub_choice;
        	cout << "From customer, what do you need?" << endl;
            cout << "1. To record information about customer" << endl;
            cout << "2. To display every information about product" << endl;
            cin >> sub_choice;
            if (sub_choice == 1) {
                 Customer(cs, n, conn);
            } else if (sub_choice == 2) {
                 display(pro, n,conn);
            } else {
                cout << "Invalid choice" << endl;
            }
               
            break;
        }
        case 4: {
            Supplier(sp, n, conn);
            break;
        }
        case 5: {
                employee(e, n, conn);
            break;
        }
        case 6: {
            int sub_choice;
            cout << "From transaction, what do you need?" << endl;
            cout << "1. To record all transactions we have" << endl;
            cout << "2. To display every information" << endl;
            cin >> sub_choice;
            if (sub_choice == 1) {
                Transaction(tr, n, conn);
            } else if (sub_choice == 2) {
                displayTransaction(tr, n,conn);
            } else {
                cout << "Invalid choice" << endl;
            }
            break;
        }
        default:
            cout << "Wrong choice." << endl;
    }
}

int main() {
    MYSQL *conn;
    int n = 10; // Default array size for simplicity
    product pro[n];
    store st[n];
    customer cs[n];
    supplier sp[n];
    Employee e[n];
    transaction tr[n];
    bool programIsOpened = true;
    int answer;

    conn = mysql_init(0);
    if (conn == NULL) {
        cerr << "MySQL initialization failed." << endl;
        return 1;
    }

    conn = mysql_real_connect(conn, HOST, USER, PASS, DB, 3306, NULL, 0);
    if (conn) {
        cout << "Logged in." << endl << endl;
        while (programIsOpened) {
            int choice;
            cout << "\t\tHi, welcome to our supermarket!!" << endl;
                cout << "What do you need to do?" << endl;
                cout << "1. Go to product" << endl;
                cout << "2. Go to store" << endl;
                cout << "3. Go to customer" << endl;
                cout << "4. Go to supplier" << endl;
                cout << "5. Go to employee" << endl;
                cout << "6. Go to transaction" << endl;
                cin >> choice;
                all_display(pro, st, cs, sp, e, tr, choice, n, conn);
           

            if (mysql_ping(conn)) {
                cerr << "Error: Impossible to connect." << endl;
                cerr << mysql_error(conn) << endl;
            }
            cout << "Another?" << endl;
            cout << "[1]: Yes" << endl;
            cout << "[0]: No" << endl;
            cout << "Answer: ";
            cin >> answer;
            if (answer == 0) {
                programIsOpened = false;
            }
            cout << endl;
        }
    } else {
        cerr << "Connection failed: " << mysql_error(conn) << endl;
    }

    cout << "BYE!!" << endl;
    mysql_close(conn);
    return 0;
}

