#include <conio.h>

#include <cctype>  // For toupper() or tolower()
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
// File Handling Functions Prototypes

// Data Saving

void clientDataSaving(int clientID[], string clientName[],
                      string clientContact[], string clientUserName[],
                      string clientPassword[], int generalDBSize);
void inventoryDataSaving(int invID[], string invName[], int invModelYear[],
                         int invPopRating[], string invStatus[], int invPrice[],
                         int generalDBSize);
void orderDataSaving(int orderID[], int orderClientID[], int orderCarID[],
                     string orderStatus[], string orderDate[],
                     string appointmentDate[], string appointmentTime[],
                     string saleDates[], int generalDBSize);
void managerDataSaving(string managerSecurityQuestion,
                       string managerSecurityAnswer, string managerUserName,
                       string managerPassword);

// Data Loading

void clientDataLoading(int clientID[], string clientName[],
                       string clientContact[], string clientUserName[],
                       string clientPassword[], int generalDBSize);
void inventoryDataLoading(int invID[], string invName[], int invModelYear[],
                          int invPopRating[], string invStatus[],
                          int invPrice[], int generalDBSize);
void orderDataLoading(int orderID[], int orderClientID[], int orderCarID[],
                      string orderStatus[], string orderDate[],
                      string appointmentDate[], string appointmentTime[],
                      string saleDates[], int generalDBSize);
void managerDataLoading(string managerSecurityQuestion,
                        string managerSecurityAnswer, string managerUserName,
                        string managerPassword);

// Input Validations For All Inputs
int validateID(int generalDBSize);
int getValidMenuChoice(int minChoice, int maxChoice);
int validatePrice();
char validateYesNoInput();
string validateNameInput();
string validateContactNumber();
string passwordValidator();
int validateModelYear();
int validatePopularityRating();
string validateDate();
string validateTime();
// Anonmous Function Prototypes
bool isUsernameTaken(string clientUsernames[], string& username, int size);
bool emptinessCheckerforIDs(int idArray[], int size);
bool clientHasOrders(int orderClientID[], int size, int& loggedInClientID);
bool hasComplaints(int complaintClientID[], int generalDBSize,
                   int loggedInClientID);
// Functions Protoypes to Check for Space
bool checkSpaceInt(int arr[], int size);
bool checkSpaceStr(string arr[], int size);
// Functions Prototypes to have empty Indexes
int outputEmptyIndexInt(int arr[], int size);
int outputEmptyIndexStr(string arr[], int size);
// Manager Login Checker
bool managerLoginAndRecovery(string managerUserName, string& managerPassword,
                             string managerSecurityQuestion,
                             string managerSecurityAnswer);
// Client Login Checker
bool loginClient(string userName[], string password[], int clientID[],
                 int generalDBSize, string inputUserName, string inputPassword,
                 int& loggedInClientID);
// Function Prototype of varoius Menus
void cdmPrint();
void mainMenuPrint();

// Manager Menu and SubMenu Printing Prototypes
void managerMenusPrint();
void inventoryManagement();
void clientManagement();
void orderManagement();
void salesRecordsManagement();
// Inventory Management Functions prototype
bool addInv(int invID[], string invName[], int invModelYear[],
            int invPopRating[], string invStatus[], int invPrice[],
            const int generalDBSize);
void editInv(int invID[], string invName[], int invModelYear[],
             int invPopRating[], string invStatus[], int invPrice[],
             const int generalDBSize);
void deleteInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size);
void printInv(int invID[], string invName[], int invModelYear[],
              int invPopRating[], string invStatus[], int invPrice[], int size);
void searchInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size);
void filterInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size);

// Client Management Functions prototype
void printClients(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size);
bool deleteClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size);
bool updateClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size);
void searchClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size);
void filterClientsForManager(int orderID[], int orderClientID[],
                             string orderStatus[], int clientID[],
                             string clientName[], string contactNumber[],
                             int size);
void manageAllComplaints(int complaintID[], int complaintClientID[],
                         string complaintDetails[], string complaintReply[],
                         string clientName[], int size);
void replyToComplaint(int complaintID[], string complaintDetails[],
                      string complaintReply[], int size);
void manageSuggestions(int suggestionID[], int suggestionClientID[],
                       string suggestionDetails[], int size);

// Order Management Functions prototype
void viewAllOrders(int orderID[], int orderClientID[], int orderCarID[],
                   string orderStatus[], string orderDate[],
                   string appointmentDate[], string appointmentTime[],
                   int size);
void approveOrder(int orderID[], int orderClientID[], int orderCarID[],
                  string orderStatus[], string orderDate[],
                  string appointmentDate[], string appointmentTime[],
                  string invStatus[], int invID[], string saleDates[],
                  int size);

// Sales Record Management Functions prototype
void printAllSales(int orderID[], int orderClientID[], int orderCarID[],
                   string orderStatus[], int invID[], string invName[],
                   int invPrice[], string saleDates[], int generalDBSize);
void deleteSale(int orderID[], string orderStatus[], string saleDates[],
                int invID[], string invStatus[], int generalDBSize);
void filterSalesByDate(int orderID[], int orderClientID[], int orderCarID[],
                       string orderStatus[], int invID[], string invName[],
                       int invPrice[], string saleDates[], int generalDBSize);
// Manager Profile Setting Prototype
void manageManagerSettings(string& managerSecurityQuestion,
                           string& managerSecurityAnswer,
                           string& managerUserName, string& managerPassword);
// Client Menu and Sub Menu Prototypes
void clientMenuPrint();
void viewInventory();
void orderCar();
void orderHistory();
void complainSubmission();
void suggestionSubmission();

// Inventory viewing Functions prototype
void printCarsForClient(int invID[], string invName[], int invModelYear[],
                        int invPopRating[], string invStatus[], int invPrice[],
                        int size);
void filterCarsByPrice(int invID[], string invName[], int invModelYear[],
                       int invPopRating[], string invStatus[], int invPrice[],
                       int size);
void filterCarsByPopularity(int invID[], string invName[], int invModelYear[],
                            int invPopRating[], string invStatus[],
                            int invPrice[], int size);

// Order inventory Functions prototype
void searchAvailableCars(int invID[], string invName[], int invModelYear[],
                         int invPopRating[], string invStatus[], int invPrice[],
                         int generalDBSize);
bool placeOrder(int orderID[], int orderClientID[], int orderCarID[],
                string orderStatus[], string orderDate[], int clientID,
                int invID[], string invName[], string invStatus[],
                int generalDBSize);

// Order History Functions prototype
void printClientCurrentOrders(int orderID[], int orderClientID[],
                              int orderCarID[], string orderStatus[],
                              string appointmentDate[],
                              string appointmentTime[], int invID[],
                              string invName[], int invPrice[], int size,
                              int& loggedInClientID);
void printClientCompletedOrders(int orderID[], int orderClientID[],
                                int orderCarID[], string orderStatus[],
                                int invID[], string invName[], int invPrice[],
                                int generalDBSize, int& loggedInClientID);
void deleteCurrentClientOrder(int orderID[], int orderClientID[],
                              int orderCarID[], string orderStatus[],
                              string appointmentDate[],
                              string appointmentTime[], int generalDBSize,
                              int& loggedInClientID);

// Complaint Submission Functions prototype
void submitComplaint(int complaintID[], int complaintClientID[],
                     string complaintDetails[], string complaintReply[],
                     int generalDBSize, int& loggedInClientID);
void viewComplaintsAndReplies(int complaintID[], int complaintClientID[],
                              string complaintDetails[],
                              string complaintReply[], int generalDBSize,
                              int& loggedInClientID);
void deleteComplaint(int complaintID[], int complaintClientID[],
                     string complaintDetails[], string complaintReply[],
                     int& loggedInClientID, int generalDBSize);

// Suggestion Submission Function prototypes
void submitSuggestion(int suggestionID[], int suggestionClientID[],
                      string suggestionDetails[], int& loggedInClientID,
                      int size);
void deleteSuggestion(int suggestionID[], int suggestionClientID[],
                      string suggestionDetails[], int& loggedInClientID,
                      int maxSize);

// Profile Setting Client
void profileSettingsClient(int& loggedInClientID, string userName[],
                           string password[], string clientName[],
                           string contactNumber[], int generalDBSize);
// Signup Menu Prototypes
void signupMenuPrint();
bool signupClient(int clientID[], string clientNames[], string clientContacts[],
                  string clientUsernames[], string clientPasswords[],
                  int generalDBSize);

// Array Initializer Function Prototypes
void initializeIntArray(int arr[], int size);
void initializeStringArray(string arr[], int size);

int main() {
    // Initializing Necessary Attributes and Contents
    const int generalDBSize = 50;

    // Attributes Related to inventory
    int invID[generalDBSize];
    string invName[generalDBSize];
    int invModelYear[generalDBSize];
    int invPopRating[generalDBSize];
    string invStatus[generalDBSize];
    int invPrice[generalDBSize];

    // Attributes Related to Client
    int clientID[generalDBSize];
    string clientName[generalDBSize];
    string clientContact[generalDBSize];
    string clientUserName[generalDBSize];
    string clientPassword[generalDBSize];

    // Attributes Related to Orders
    int orderID[generalDBSize];
    int orderClientID[generalDBSize];
    int orderCarID[generalDBSize];
    string orderStatus[generalDBSize];
    string orderDate[generalDBSize];
    string appointmentDate[generalDBSize];
    string appointmentTime[generalDBSize];
    // Attributes Related to Complaints/Queries
    int complaintID[generalDBSize];
    int complaintClientID[generalDBSize];
    string complaintDetails[generalDBSize];
    string complaintReply[generalDBSize];

    // Attributes Related to Suggestion
    int suggestionID[generalDBSize];
    int suggestionClientID[generalDBSize];
    string suggestionDetails[generalDBSize];
    // Attributes Related to Sales
    string saleDates[generalDBSize];
    int input = -1;
    int loginUserType =
        -2;  // This will decide the Menu in which we are right now
    int loggedInClientID = -1;
    double serviceRating;
    string managerSecurityQuestion = "What is your favorite color?";
    string managerSecurityAnswer = "Blue";
    string managerUserName = "Admin123", managerPassword = "Admin123";
    string username = "", password = "";  // This is for  user name and password
    // Initializing All Arrays to a default Value

    // Inventory Related Arrays
    initializeIntArray(invID, generalDBSize);
    initializeStringArray(invName, generalDBSize);
    initializeIntArray(invModelYear, generalDBSize);
    initializeIntArray(invPopRating, generalDBSize);
    initializeStringArray(invStatus, generalDBSize);
    initializeIntArray(invPrice, generalDBSize);

    // Client Related Arrays
    initializeIntArray(clientID, generalDBSize);
    initializeStringArray(clientName, generalDBSize);
    initializeStringArray(clientContact, generalDBSize);
    initializeStringArray(clientUserName, generalDBSize);
    initializeStringArray(clientPassword, generalDBSize);
    // Initialize arrays related to Orders
    initializeIntArray(orderID, generalDBSize);
    initializeIntArray(orderClientID, generalDBSize);
    initializeIntArray(orderCarID, generalDBSize);
    initializeStringArray(orderStatus, generalDBSize);
    initializeStringArray(orderDate, generalDBSize);
    initializeStringArray(appointmentDate, generalDBSize);
    initializeStringArray(appointmentTime, generalDBSize);
    initializeStringArray(saleDates, generalDBSize);

    // Initialize arrays related to Complaints/Queries
    initializeIntArray(complaintID, generalDBSize);
    initializeIntArray(complaintClientID, generalDBSize);
    initializeStringArray(complaintDetails, generalDBSize);
    initializeStringArray(complaintReply, generalDBSize);

    // Initialize arrays related to Suggestions
    initializeIntArray(suggestionID, generalDBSize);
    initializeIntArray(suggestionClientID, generalDBSize);
    initializeStringArray(suggestionDetails, generalDBSize);

    // Calling data loading Functions
    clientDataLoading(clientID, clientName, clientContact, clientUserName,
                      clientPassword, generalDBSize);
    inventoryDataLoading(invID, invName, invModelYear, invPopRating, invStatus,
                         invPrice, generalDBSize);
    orderDataLoading(orderID, orderClientID, orderCarID, orderStatus, orderDate,
                     appointmentDate, appointmentTime, saleDates,
                     generalDBSize);
    managerDataLoading(managerSecurityQuestion, managerSecurityAnswer,
                       managerUserName, managerPassword);

    system("chcp 65001");  // This is Necessary for printing cdmPrint
    system("cls");

    do {
        cdmPrint();
        mainMenuPrint();
        cout << "\n\t\t\tEnter your choice (0 - 3): ";
        input = getValidMenuChoice(0, 3);

        switch (input) {
            case 1:
                system("cls");
                cdmPrint();
                if (managerLoginAndRecovery(managerUserName, managerPassword,
                                            managerSecurityQuestion,
                                            managerSecurityAnswer)) {
                    loginUserType = 1;
                }

                break;
            case 2:

                system("cls");
                cdmPrint();
                cout << endl << endl;
                if (!emptinessCheckerforIDs(clientID, generalDBSize)) {
                    cout << "\t\tEnter Username: ";
                    getline(cin, username);

                    cout << "\t\tEnter Password: ";
                    password = passwordValidator();

                    if ((loginClient(clientUserName, clientPassword, clientID,
                                     generalDBSize, username, password,
                                     loggedInClientID))) {
                        loginUserType = 2;
                    }
                } else {
                    cout << "\t\tNo Client has signedUp yet So you Cannot "
                            "Login.\n \t\tGo and SignUp First in Previous "
                            "Menu\n";
                    cout << "\t\tPress Any Key to move back to Previous Menu";
                    getch();
                }
                break;
            case 3:

                loginUserType = 3;

                break;

            case 0:
                system("cls");
                cdmPrint();
                cout << endl << endl;

                cout << endl
                     << "\t\tThank You For Using Car Dealership SYSTEM!!...";
                break;
            default:
                cout << endl << endl;

                cout << "INVALID CHOICE Try Again!!";
                break;
        }

        if (loginUserType == 1) {
            do {
                system("cls");
                cdmPrint();
                cout << endl << endl;
                managerMenusPrint();
                cout << "\n\t\t\tEnter your choice (0-5): ";
                input = getValidMenuChoice(0, 5);
                switch (input) {
                    case 1:
                        do {
                            system("cls");
                            cdmPrint();
                            inventoryManagement();
                            cout << "\n\t\t\tEnter your choice (0-6): ";
                            input = getValidMenuChoice(0, 6);

                            switch (input) {
                                case 1:
                                    if (!addInv(invID, invName, invModelYear,
                                                invPopRating, invStatus,
                                                invPrice, generalDBSize)) {
                                        cout << "\n\t\tCould not add the car. "
                                                "No space available."
                                             << endl;
                                    }
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();

                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        editInv(invID, invName, invModelYear,
                                                invPopRating, invStatus,
                                                invPrice, generalDBSize);
                                    } else
                                        cout << "\t\tNo Data is Entered that "
                                                "can be Editted\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();

                                    break;
                                case 3:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        deleteInv(invID, invName, invModelYear,
                                                  invPopRating, invStatus,
                                                  invPrice, generalDBSize);
                                    } else
                                        cout << "\t\tNo Data is Entered that "
                                                "can "
                                                "be deleted\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();
                                    break;

                                case 4:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        printInv(invID, invName, invModelYear,
                                                 invPopRating, invStatus,
                                                 invPrice, generalDBSize);
                                    } else
                                        cout << "\t\tNo Data is Entered that "
                                                "can "
                                                "be Listed/Printed\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();
                                    break;
                                case 5:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        searchInv(invID, invName, invModelYear,
                                                  invPopRating, invStatus,
                                                  invPrice, generalDBSize);
                                    } else
                                        cout << "\t\tNo Data is Entered that "
                                                "can "
                                                "be Searched\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();
                                    break;

                                case 6:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        filterInv(invID, invName, invModelYear,
                                                  invPopRating, invStatus,
                                                  invPrice, generalDBSize);
                                    } else
                                        cout << "\t\tNo Data is Entered that "
                                                "can "
                                                "be Filtered\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();
                                    break;

                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop
                        break;
                    case 2:
                        do {
                            system("cls");
                            cdmPrint();
                            clientManagement();
                            cout << "\n\t\t\tEnter your choice (0-8): ";
                            input = getValidMenuChoice(0, 8);

                            switch (input) {
                                case 1:
                                    if (!emptinessCheckerforIDs(
                                            clientID, generalDBSize)) {
                                        printClients(
                                            clientID, clientName,
                                            clientUserName, clientContact,
                                            clientPassword, generalDBSize);
                                    } else
                                        cout << "\t\tNo Client has SignedUp "
                                                "Yet\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();
                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            clientID, generalDBSize)) {
                                        deleteClient(
                                            clientID, clientName,
                                            clientUserName, clientContact,
                                            clientPassword, generalDBSize);
                                    } else
                                        cout << "\t\tNo Client has SignedUp "
                                                "Yet So YOu Cannot delete "
                                                "them\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();

                                    break;
                                case 3:
                                    if (!emptinessCheckerforIDs(
                                            clientID, generalDBSize)) {
                                        updateClient(
                                            clientID, clientName,
                                            clientUserName, clientContact,
                                            clientPassword, generalDBSize);
                                    } else
                                        cout << "\t\tNo Client has SignedUp "
                                                "Yet So You Cannot Edit "
                                                "them\n";
                                    cout << "\t\tPress Any Key to Move Back to "
                                            "previous Menu";
                                    getch();

                                    break;

                                case 4:
                                    if (!emptinessCheckerforIDs(
                                            clientID, generalDBSize)) {
                                        searchClient(
                                            clientID, clientName,
                                            clientUserName, clientContact,
                                            clientPassword, generalDBSize);
                                    } else
                                        cout << "\t\tNo Client has SignedUp "
                                                "Yet So You Cannot Search for "
                                                "client "
                                                "them\n";
                                    cout << "\n\t\tPress Any Key to Move Back "
                                            "to "
                                            "previous Menu";
                                    getch();
                                    break;
                                case 5:
                                    if (!emptinessCheckerforIDs(
                                            clientID, generalDBSize)) {
                                        filterClientsForManager(
                                            orderID, orderClientID, orderStatus,
                                            clientID, clientName, clientContact,
                                            generalDBSize);
                                    } else {
                                        cout << "\t\tNo Client has SignedUp "
                                                "Yet So You Cannot Search for "
                                                "client "
                                                "them\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }

                                    break;

                                case 6:
                                    if (!emptinessCheckerforIDs(
                                            complaintID, generalDBSize)) {
                                        manageAllComplaints(
                                            complaintID, complaintClientID,
                                            complaintDetails, complaintReply,
                                            clientName, generalDBSize);
                                    } else {
                                        cout << "\t\tNo Client has SignedUp "
                                                "For a complaint yet \n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }

                                    break;
                                case 7:
                                    if (!emptinessCheckerforIDs(
                                            complaintID, generalDBSize)) {
                                        replyToComplaint(
                                            complaintID, complaintDetails,
                                            complaintReply, generalDBSize);
                                    } else {
                                        cout << "\t\tNo Client has SignedUp "
                                                "For a complaint yet \n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }

                                    break;
                                case 8:
                                    if (!emptinessCheckerforIDs(
                                            suggestionID, generalDBSize)) {
                                        manageSuggestions(
                                            suggestionID, suggestionClientID,
                                            suggestionDetails, generalDBSize);
                                    } else {
                                        cout << "\t\tNo Client has  "
                                                "submitted a suggestion yet \n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }
                                    break;

                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 3:
                        do {
                            system("cls");
                            cdmPrint();
                            orderManagement();
                            cout << "\n\t\t\tEnter your choice (0-2): ";
                            input = getValidMenuChoice(0, 2);
                            switch (input) {
                                case 1:
                                    if (!emptinessCheckerforIDs(
                                            orderID, generalDBSize)) {
                                        viewAllOrders(
                                            orderID, orderClientID, orderCarID,
                                            orderStatus, orderDate,
                                            appointmentDate, appointmentTime,
                                            generalDBSize);
                                    } else {
                                        cout << "\t\tNo Orders "
                                                " yet \n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }

                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            orderID, generalDBSize)) {
                                        approveOrder(orderID, orderClientID,
                                                     orderCarID, orderStatus,
                                                     orderDate, appointmentDate,
                                                     appointmentTime, invStatus,
                                                     invID, saleDates,
                                                     generalDBSize);
                                    } else {
                                        cout << "\t\tNo Orders   "
                                                " yet to Approve\n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }
                                    break;
                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 4:
                        do {
                            system("cls");
                            cdmPrint();
                            salesRecordsManagement();
                            cout << "\n\t\t\tEnter your choice (0-3): ";
                            input = getValidMenuChoice(0, 3);

                            switch (input) {
                                case 1:
                                    if (!emptinessCheckerforIDs(
                                            orderID, generalDBSize)) {
                                        printAllSales(orderID, orderClientID,
                                                      orderCarID, orderStatus,
                                                      invID, invName, invPrice,
                                                      saleDates, generalDBSize);
                                    } else {
                                        cout << "\t\tNo Sales   "
                                                " yet to Show\n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }
                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            orderID, generalDBSize)) {
                                        deleteSale(orderID, orderStatus,
                                                   saleDates, invID, invStatus,
                                                   generalDBSize);
                                    } else {
                                        cout << "\t\tNo Sales   "
                                                " yet to Delete\n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }
                                    break;
                                case 3:
                                    if (!emptinessCheckerforIDs(
                                            orderID, generalDBSize)) {
                                        filterSalesByDate(
                                            orderID, orderClientID, orderCarID,
                                            orderStatus, invID, invName,
                                            invPrice, saleDates, generalDBSize);
                                    } else {
                                        cout << "\t\tNo sales   "
                                                " yet to show\n";

                                        cout << "\t\tPress Any Key to Move "
                                                "Back to "
                                                "previous Menu";
                                        getch();
                                    }
                                    break;
                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 5:

                        manageManagerSettings(managerSecurityQuestion,
                                              managerSecurityAnswer,
                                              managerUserName, managerPassword);

                        input = -1;  // To Staay in outer Loop

                        break;

                    default:
                        system("cls");
                        cdmPrint();
                        cout << "Invalid choice.\n";
                        break;
                }
            } while (input != 0);
            loginUserType = -2;
            input = -1;  // In Order to Stay in Outer Loop
        }

        else if (loginUserType == 2) {
            do {
                system("cls");
                cdmPrint();
                cout << endl;
                clientMenuPrint();
                cout << "\n\t\t\tEnter your choice (0-6): ";
                input = getValidMenuChoice(0, 6);

                switch (input) {
                    do {
                        case 1:
                            system("cls");
                            cdmPrint();
                            viewInventory();
                            cout << "\n\t\t\tEnter your choice (0-3): ";
                            input = getValidMenuChoice(0, 3);
                            // here I will validate this Input

                            switch (input) {
                                case 1:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        printCarsForClient(
                                            invID, invName, invModelYear,
                                            invPopRating, invStatus, invPrice,
                                            generalDBSize);

                                    } else {
                                        cout << "\t\tNo Car Has Been Added by "
                                                "the ShowRoom Manager\n";
                                        cout << "\t\tPlease Visit Back Later\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }

                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        filterCarsByPrice(
                                            invID, invName, invModelYear,
                                            invPopRating, invStatus, invPrice,
                                            generalDBSize);
                                    } else {
                                        cout << "\t\tNo Car Has Been Added by "
                                                "the ShowRoom Manager\n";
                                        cout << "\t\tPlease Visit Back Later\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;
                                case 3:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        filterCarsByPopularity(
                                            invID, invName, invModelYear,
                                            invPopRating, invStatus, invPrice,
                                            generalDBSize);
                                    } else {
                                        cout << "\t\tNo Car Has Been Added by "
                                                "the ShowRoom Manager\n";
                                        cout << "\t\tPlease Visit Back Later\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;

                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                    } while (input != 0);
                    input = -1;  // To Staay in outer Loop

                    break;
                    case 2:
                        do {
                            system("cls");
                            cdmPrint();
                            orderCar();
                            cout << "\n\t\t\tEnter your choice (0-2): ";
                            input = getValidMenuChoice(0, 2);
                            // here I will validate this Input

                            switch (input) {
                                case 1:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        searchAvailableCars(
                                            invID, invName, invModelYear,
                                            invPopRating, invStatus, invPrice,
                                            generalDBSize);
                                    } else {
                                        cout << "\t\tNo Car Has Been Added by "
                                                "the ShowRoom Manager\n";
                                        cout << "\t\tPlease Visit Back Later\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;
                                case 2:
                                    if (!emptinessCheckerforIDs(
                                            invID, generalDBSize)) {
                                        placeOrder(orderID, orderClientID,
                                                   orderCarID, orderStatus,
                                                   orderDate, loggedInClientID,
                                                   invID, invName, invStatus,
                                                   generalDBSize);

                                    } else {
                                        cout << "\t\tNo Car Has Been Added by "
                                                "the ShowRoom Manager\n";
                                        cout << "\t\tPlease Visit Back Later\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;

                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 3:
                        do {
                            system("cls");
                            cdmPrint();
                            orderHistory();
                            cout << "\n\t\t\tEnter your choice (0-3): ";
                            input = getValidMenuChoice(0, 3);
                            // here I will validate this Input

                            switch (input) {
                                case 1:
                                    if (clientHasOrders(orderClientID,
                                                        generalDBSize,
                                                        loggedInClientID)) {
                                        printClientCurrentOrders(
                                            orderID, orderClientID, orderCarID,
                                            orderStatus, appointmentDate,
                                            appointmentTime, invID, invName,
                                            invPrice, generalDBSize,
                                            loggedInClientID);
                                    } else {
                                        cout << "\t\tYou Are Not Having "
                                                "Any Ongoing Orders\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }

                                    break;
                                case 2:
                                    if (clientHasOrders(orderClientID,
                                                        generalDBSize,
                                                        loggedInClientID)) {
                                        printClientCompletedOrders(
                                            orderID, orderClientID, orderCarID,
                                            orderStatus, invID, invName,
                                            invPrice, generalDBSize,
                                            loggedInClientID);
                                    } else {
                                        cout << "\t\tYou Are Not Having "
                                                "Any Ongoing Orders\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;
                                case 3:
                                    if (clientHasOrders(orderClientID,
                                                        generalDBSize,
                                                        loggedInClientID)) {
                                        deleteCurrentClientOrder(
                                            orderID, orderClientID, orderCarID,
                                            orderStatus, appointmentDate,
                                            appointmentTime, generalDBSize,
                                            loggedInClientID);
                                    } else {
                                        cout << "\t\tYou Are Not Having "
                                                "Any Ongoing Orders\n";
                                        cout << "\t\tPress Any Key to Move "
                                                "Back to Previous Menu";
                                        getch();
                                    }
                                    break;

                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 4:
                        do {
                            system("cls");
                            cdmPrint();
                            complainSubmission();
                            cout << "\n\t\t\tEnter your choice (0-3): ";
                            input = getValidMenuChoice(0, 3);
                            // here I will validate this Input

                            switch (input) {
                                case 1:
                                    submitComplaint(
                                        complaintID, complaintClientID,
                                        complaintDetails, complaintReply,
                                        generalDBSize, loggedInClientID);
                                    break;
                                case 2:
                                    if (hasComplaints(complaintClientID,
                                                      generalDBSize,
                                                      loggedInClientID)) {
                                        viewComplaintsAndReplies(
                                            complaintID, complaintClientID,
                                            complaintDetails, complaintReply,
                                            generalDBSize, loggedInClientID);
                                    } else {
                                        cout << "\n\t\tYou haven't submitted "
                                                "any complaints yet."
                                             << endl;
                                        cout << "\t\tPress Any Key to Move "
                                                "Back TO Previous menu";
                                        getch();
                                    }
                                    break;

                                case 3:
                                    if (hasComplaints(complaintClientID,
                                                      generalDBSize,
                                                      loggedInClientID)) {
                                        deleteComplaint(
                                            complaintID, complaintClientID,
                                            complaintDetails, complaintReply,
                                            loggedInClientID, generalDBSize);
                                    } else {
                                        cout << "\n\t\tYou haven't submitted "
                                                "any complaints yet."
                                             << endl;
                                        cout << "\t\tPress Any Key to Move "
                                                "Back TO Previous menu";
                                        getch();
                                    }

                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 5:
                        do {
                            system("cls");
                            cdmPrint();
                            suggestionSubmission();
                            cout << "\n\t\t\tEnter your choice (0-2): ";
                            input = getValidMenuChoice(0, 2);
                            // here I will validate this Input

                            switch (input) {
                                case 1:

                                    submitSuggestion(
                                        suggestionID, suggestionClientID,
                                        suggestionDetails, loggedInClientID,
                                        generalDBSize);
                                    break;

                                case 2:
                                    deleteSuggestion(
                                        suggestionID, suggestionClientID,
                                        suggestionDetails, loggedInClientID,
                                        generalDBSize);
                                default:
                                    cout << "\t\tYou Entered Invalid Input "
                                            "Please Try Again\n";
                                    break;
                            }
                        } while (input != 0);
                        input = -1;  // To Staay in outer Loop

                        break;
                    case 6:

                        system("cls");
                        cdmPrint();
                        profileSettingsClient(loggedInClientID, clientUserName,
                                              clientPassword, clientName,
                                              clientContact, generalDBSize);

                        input = -1;  // To Staay in outer Loop

                        break;

                    default:
                        system("cls");
                        cdmPrint();
                        cout << "Invalid choice.\n";
                        break;
                }

            } while (input != 0);
            loginUserType = -2;
            input = -1;  // In Order to Stay in Outer Loop
        }

        else if (loginUserType == 3) {
            do {
                system("cls");
                cdmPrint();
                cout << endl << endl;
                signupMenuPrint();
                cout << "\n\t\t\tEnter your choice (0-1): ";
                input = getValidMenuChoice(0, 1);

                switch (input) {
                    case 1:
                        system("cls");
                        cdmPrint();
                        signupClient(clientID, clientName, clientContact,
                                     clientUserName, clientPassword,
                                     generalDBSize);
                        cout << "\t\tPress Any Key to Move Back to "
                                "Main Menu";
                        getch();
                        input = 0;
                        break;
                    default:
                        system("cls");
                        cdmPrint();
                        cout << "Invalid Choice";
                        break;
                }
            } while (input != 0);
            loginUserType = -2;
            input = -1;  // In Order to Stay in Outer Loop
        } else if (loginUserType == -1) {
            cout << "Dear User You Entered Invalid Credentials";

            cout << endl << "\t\tPress any key to try again ......";
            getch();
        }
    } while (input != 0);

    // Calling Data Saving Functions
    clientDataSaving(clientID, clientName, clientContact, clientUserName,
                     clientPassword, generalDBSize);
    inventoryDataSaving(invID, invName, invModelYear, invPopRating, invStatus,
                        invPrice, generalDBSize);
    orderDataSaving(orderID, orderClientID, orderCarID, orderStatus, orderDate,
                    appointmentDate, appointmentTime, saleDates, generalDBSize);
    managerDataSaving(managerSecurityQuestion, managerSecurityAnswer,
                      managerUserName, managerPassword);
    cout << "\n\t\tPress Any Key To Terminate Terminal...";
    getch();
    return 0;
}

// Checker Function Definitions
bool isUsernameTaken(string clientUsernames[], string& username, int size) {
    for (int i = 0; i < size; i++) {
        if (clientUsernames[i] == username) {
            return true;
        }
    }
    return false;
}
bool emptinessCheckerforIDs(int idArray[], int size) {
    for (int i = 0; i < size; i++) {
        if (idArray[i] != -99) {
            return false;
        }
    }
    return true;
}

bool clientHasOrders(int orderClientID[], int size, int& loggedInClientID) {
    for (int i = 0; i < size; i++) {
        if (orderClientID[i] == loggedInClientID) {
            return true;
        }
    }
    return false;
}
bool hasComplaints(int complaintClientID[], int generalDBSize,
                   int loggedInClientID) {
    for (int i = 0; i < generalDBSize; i++) {
        if (complaintClientID[i] == loggedInClientID) {
            return true;
        }
    }
    return false;
}

// Initializer for Various Arrays

void initializeIntArray(int arr[], int size) {
    int defaultValue = -99;
    for (int i = 0; i < size; ++i) {
        arr[i] = defaultValue;
    }
}
void initializeStringArray(string arr[], int size) {
    string defaultValue = "";
    for (int i = 0; i < size; ++i) {
        arr[i] = defaultValue;
    }
}

// function to check if there is space available in any array
bool checkSpaceInt(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == -99) {
            return true;
        }
    }
    return false;
}
bool checkSpaceStr(string arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == "") {
            return true;
        }
    }
    return false;
}
// function to find the first empty index in any array
int outputEmptyIndexInt(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == -99) {
            return i;
        }
    }
    return -1;
}
int outputEmptyIndexStr(string arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == "") {
            return i;
        }
    }
    return -1;
}

// Crededential Checker For Client
bool loginClient(string userName[], string password[], int clientID[],
                 int generalDBSize, string inputUserName, string inputPassword,
                 int& loggedInClientID) {
    for (int i = 0; i < generalDBSize; i++) {
        if (userName[i] == inputUserName) {
            if (password[i] == inputPassword) {
                loggedInClientID = clientID[i];
                cout << "\n\t\tLogin Successful! Welcome, " << userName[i]
                     << " (Client ID: " << clientID[i] << ")\n";
                cout << "\t\tPress Any Key to move  to Next Menu";
                getch();
                return true;
            } else {
                cout << "\n\t\tIncorrect Password!\n";
                cout << "\t\tPress Any Key to move back to Previous Menu";
                getch();
                return false;
            }
        }
    }
    cout << "\n\t\tUsername not found! Please check your username and try "
            "again.\n";
    cout << "\t\tPress Any Key to move back to Previous Menu";
    getch();
    return false;
}
// Credential Checker For Manager

bool managerLoginAndRecovery(string managerUserName, string& managerPassword,
                             string managerSecurityQuestion,
                             string managerSecurityAnswer) {
    string username, password, securityAnswer;
    int option;

    cout << endl << endl;
    cout << "\t\tEnter Username: ";
    getline(cin, username);
    cout << "\t\tEnter Password: ";
    password = passwordValidator();

    if (username == managerUserName && password == managerPassword) {
        cout << "\n\t\tLogin successful as Manager.\n";
        cout << "\t\tPress Any Key To Proceed As a Manager";
        getch();
        return true;
    } else {
        cout << "\n\t\tIncorrect password. Would you like to:\n";
        cout << "\t\t1. Try account recovery\n";
        cout << "\t\t0. Go back to main menu\n";
        cout << "\n\t\t\tEnter your choice (0-1): ";
        option = getValidMenuChoice(0, 1);

        if (option == 0) {
            cout << "\n\t\tReturning to the main menu...\n";
            return false;
        } else if (option == 1) {
            // Check if security question is empty
            if (!managerSecurityQuestion.empty() &&
                !managerSecurityAnswer.empty()) {
                cout << "\n\t\tAccount Recovery - Security Question:\n";
                cout << "\t\t" << managerSecurityQuestion << endl;
                cout << "\t\tYour Answer: ";
                getline(cin, securityAnswer);

                if (securityAnswer == managerSecurityAnswer) {
                    cout << "\n\t\tAnswer is correct. You can now change your "
                            "password.\n";
                    cout << "\t\tEnter your new password: ";
                    managerPassword = passwordValidator();
                    cout << "\n\t\tYour password has been successfully "
                            "updated.\n";
                    cout << "\t\tYou have got Manager Access\n\t\tPress Any "
                            "Key to move  to Manager Menu ";
                    getch();

                    return true;
                } else {
                    cout << "\n\t\tIncorrect answer to the security question. "
                            "\n";
                    cout << "\t\tPress Any Key to move back to Main Menu";
                    getch();

                    return false;
                }
            } else {
                cout << "\n\t\tNo security question has been set.\n";
                cout << "\t\tHence you Cannot Recover you Password\n";
                cout << "\t\tPress Any Key to Move Back To Previous Menu";
                getch();
                return false;
            }
        } else {
            cout << "\n\t\tInvalid option selected.\n";
            cout << "\t\tPress Any Key to Move Back To Previous Menu";
            getch();
            return false;
        }
    }
}

void cdmPrint() {
    system("cls");

    cout << " ██████  █████  ██████      ██████  ███████  █████  ██      "
            "███████ ██████  ███████ ██   ██ ██ ██████ "
         << endl;
    cout << "██      ██   ██ ██   ██     ██   ██ ██      ██   ██ ██      "
            "██    "
            "  ██   ██ ██      ██   ██ ██ ██   ██"
         << endl;
    cout << "██      ███████ ██████      ██   ██ █████   ███████ ██      "
            "█████ "
            "  ██████  ███████ ███████ ██ ██████ "
         << endl;
    cout << "██      ██   ██ ██   ██     ██   ██ ██      ██   ██ ██      "
            "██    "
            "  ██   ██      ██ ██   ██ ██ ██     "
         << endl;
    cout << " ██████ ██   ██ ██   ██     ██████  ███████ ██   ██ ███████ "
            "███████ ██   ██ ███████ ██   ██ ██ ██     "
         << endl;
}

// Menus Printing Functions

void mainMenuPrint() {
    cout << "\n\n\t\t\tMain Menu \n";
    cout << "\t\t\t1. Manager Access\n";
    cout << "\t\t\t2. Client Access\n";
    cout << "\t\t\t3. Client SignUp Page\n";
    cout << "\t\t\t0. Terminate Application\n\n";
}

// Manager Related Menus
void managerMenusPrint() {
    cout << "\n\n\t\t\tManager Menu  \n";
    cout << "\t\t\t1. Inventory Management\n";
    cout << "\t\t\t2. Client Management\n";
    cout << "\t\t\t3. Order Management\n";
    cout << "\t\t\t4. Sales Record\n";
    cout << "\t\t\t5. Profile Settings\n";
    cout << "\t\t\t0. Logout\n";
}
void inventoryManagement() {
    cout << "\n\n\t\t\tInventory Management Menu  \n";
    cout << "\t\t\t1. Add Vehicle\n";
    cout << "\t\t\t2. Update Vehicle Data\n";
    cout << "\t\t\t3. Delete Vehicle Data\n";
    cout << "\t\t\t4. List All Vehicles\n";
    cout << "\t\t\t5. Search Vehicle\n";
    cout << "\t\t\t6. Filter Inventory\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void clientManagement() {
    cout << "\n\n\t\t\tClient Management Menu  \n";
    cout << "\t\t\t1. View All Clients\n";
    cout << "\t\t\t2. Delete Client Data\n";
    cout << "\t\t\t3. Edit Client Data\n";
    cout << "\t\t\t4. Search Client\n";
    cout << "\t\t\t5. Filter Clients\n";
    cout << "\t\t\t6. View Client Queries\n";
    cout << "\t\t\t7. Reply to Client Queries\n";
    cout << "\t\t\t8. View Suggestions from Clients\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void orderManagement() {
    cout << "\n\n\t\t\t Order Management Menu  \n";
    cout << "\t\t\t1. View All Orders\n";
    cout << "\t\t\t2. Approve Orders and provide clients with meeting "
            "appointments\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void salesRecordsManagement() {
    cout << "\n\n\t\t\tSales Record Management Menu  \n";
    cout << "\t\t\t1. Print All Sales Records\n";
    cout << "\t\t\t2. Delete a Sale\n";
    cout << "\t\t\t3. View Sales By Date\n";
    cout << "\t\t\t0. Previous Menu\n";
}

// Client Related Menus
void clientMenuPrint() {
    cout << "\n\n\t\t\tClient Menu  \n";
    cout << "\t\t\t1. View Inventory\n";
    cout << "\t\t\t2. Order a Car\n";
    cout << "\t\t\t3. Order History\n";
    cout << "\t\t\t4. Submit a Complaint\n";
    cout << "\t\t\t5. Submit a Suggestion\n";
    cout << "\t\t\t6. Profile Settings\n";
    cout << "\t\t\t0. Logout\n";
}
void viewInventory() {
    cout << "\n\n\t\t\tInventory  Menu  \n";
    cout << "\t\t\t1. Browse All Cars \n";
    cout << "\t\t\t2. Filter by Price Range\n";
    cout << "\t\t\t3. Sort by Popularity\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void orderCar() {
    cout << "\n\n\t\t\tCar Ordering  Menu  \n";
    cout << "\t\t\t1. View Car Details \n";
    cout << "\t\t\t2. Confirm Order\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void orderHistory() {
    cout << "\n\n\t\t\tOrder STATS Menu  \n";
    cout << "\t\t\t1. View Current Orders \n";
    cout << "\t\t\t2. View Order History\n";
    cout << "\t\t\t3. Delete Current Order\n";
    cout << "\t\t\t0. Previous Menu\n";
}
void complainSubmission() {
    cout << "\n\n\t\t\tComplaint Submission Menu  \n";
    cout << "\t\t\t1. Enter a Complaint \n";
    cout << "\t\t\t2. Response of Complaint\n";
    cout << "\t\t\t3. Delete a Complaint \n";
    cout << "\t\t\t0. Previous Menu\n";
}
void suggestionSubmission() {
    cout << "\n\n\t\t\tSuggestion Submission   \n";
    cout << "\t\t\t1. Enter a Suggestion  \n";
    cout << "\t\t\t2. Delete a Suggestion  \n";
    cout << "\t\t\t0. Previous Menu\n";
}

// SignUp Functionalities
void signupMenuPrint() {
    cout << "\n\n\t\t\tYou are signing up as a new user  \n";
    cout << "\t\t\t1. Sign Up \n";
    cout << "\t\t\t0. Previous Menu\n";
}
bool signupClient(int clientID[], string clientNames[], string clientContacts[],
                  string clientUsernames[], string clientPasswords[],
                  int generalDBSize) {
    if (!checkSpaceInt(clientID, generalDBSize)) {
        cout << "\n\n\t\tNo space available to add a new client.\n";
        return false;
    }

    int emptyIndex = outputEmptyIndexInt(clientID, generalDBSize);
    if (emptyIndex == -1) {
        cout << "\n\n\t\tNo space available to add a new client.\n";
        return false;
    }

    string name, contact, username, password;

    cout << "\n\n\t\tEnter Client Name          : ";
    name = validateNameInput();

    cout << "\n\t\tEnter Client Contact Number: ";
    contact = validateContactNumber();

    do {
        cout << "\n\t\tEnter Client Username      : ";
        getline(cin, username);

        if (isUsernameTaken(clientUsernames, username, generalDBSize)) {
            cout << "\t\tThis username is already taken. Please try another "
                    "one.\n";
        } else {
            break;
        }
    } while (true);

    cout << "\n\t\tEnter Client Password      : ";
    password = passwordValidator();

    clientID[emptyIndex] = emptyIndex;
    clientNames[emptyIndex] = name;
    clientContacts[emptyIndex] = contact;
    clientUsernames[emptyIndex] = username;
    clientPasswords[emptyIndex] = password;

    cout << "\n\t\tClient added successfully with Client ID: " << emptyIndex
         << endl;
    return true;
}

// Manager Related Functionalities

// Base Functionalities for Inventory Management

// Adding Car
bool addInv(int invID[], string invName[], int invModelYear[],
            int invPopRating[], string invStatus[], int invPrice[],
            int generalDBSize) {
    if (checkSpaceInt(invID, generalDBSize)) {
        int emptyIndex = outputEmptyIndexInt(invID, generalDBSize);

        if (emptyIndex != -1) {
            cout << "\n\t\tEnter  Car  Name           : ";
            invName[emptyIndex] = validateNameInput();

            cout << "\n\t\tEnter Car Model Year       : ";
            invModelYear[emptyIndex] = validateModelYear();

            cout << "\n\t\tEnter Car Popularity Rating: ";
            invPopRating[emptyIndex] = validatePopularityRating();

            cout << "\n\t\tEnter   Car   Price        : ";
            invPrice[emptyIndex] = validatePrice();

            invStatus[emptyIndex] = "Available";
            invID[emptyIndex] = emptyIndex;

            cout << "\n\t\tCar added successfully with ID: "
                 << invID[emptyIndex] << endl;
            return true;
        }
    }
    cout << "\n\t\tNo Space Available to Add a Car." << endl;
    return false;
}

// Updating Car Info
void editInv(int invID[], string invName[], int invModelYear[],
             int invPopRating[], string invStatus[], int invPrice[],
             int generalDBSize) {
    int carID;
    bool carFound = false;

    cout << "\n\t\tEnter the Car ID you want to edit: ";
    carID = validateID(generalDBSize);

    for (int i = 0; i < generalDBSize; ++i) {
        if (invID[i] == carID) {
            carFound = true;

            cout << "\n\t\tCurrent Details of Car ID " << carID << ": ";
            cout << "\n\t\tName: " << invName[i];
            cout << "\n\t\tModel Year: " << invModelYear[i];
            cout << "\n\t\tPopularity Rating: " << invPopRating[i];
            cout << "\n\t\tPrice: " << invPrice[i] << endl;

            cout << "\n\t\tEnter new Name : ";
            cin.ignore();
            string newName;
            newName = validateNameInput();
            if (newName != "") {
                invName[i] = newName;
            }

            cout << "\t\tEnter new Model Year : ";
            int newYear;
            newYear = validateModelYear();
            if (newYear != -1) {
                invModelYear[i] = newYear;
            }

            cout << "\t\tEnter new Popularity Rating  "
                    ": ";
            int newPopRating;
            newPopRating = validatePopularityRating();
            if (newPopRating != -1) {
                invPopRating[i] = newPopRating;
            }

            cout << "\t\tEnter new Price : ";
            int newPrice;
            newPrice = validatePrice();
            if (newPrice != -1) {
                invPrice[i] = newPrice;
            }

            cout << "\n\t\tCar details updated successfully!\n";
            break;
        }
    }

    if (!carFound) {
        cout << "\n\t\tCar ID " << carID << " not found in the inventory.\n";
    }
}
// Delete Car From Inventory
void deleteInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size) {
    int carID;
    bool found = false;

    cout << "\t\tEnter the Car ID you want to delete: ";
    carID = validateID(size);
    for (int i = 0; i < size; ++i) {
        if (invID[i] == carID) {
            found = true;

            invID[i] = -99;
            invName[i] = "";
            invModelYear[i] = -99;
            invPopRating[i] = -99;
            invStatus[i] = "";
            invPrice[i] = -99;

            cout << "\t\tCar with ID " << carID
                 << " has been deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "\t\tCar with ID " << carID << " not found!" << endl;
    }
}

// Listing car
void printInv(int invID[], string invName[], int invModelYear[],
              int invPopRating[], string invStatus[], int invPrice[],
              int size) {
    cout << left;
    cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Model Year" << setw(15) << "Pop. Rating" << setw(15) << "Status"
         << setw(25) << "Price" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;

    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        if (invID[i] != -99) {
            cout << setw(10) << invID[i] << setw(20) << invName[i] << setw(15)
                 << invModelYear[i] << setw(15) << invPopRating[i] << setw(15)
                 << invStatus[i] << setw(15) << invPrice[i] << "Pkr" << endl;
        }
    }
}

void filterInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size) {
    int option;
    cout << "\n\t\t\tFilter Inventory by:" << endl;
    cout << "\t\t\t1. Price Range" << endl;
    cout << "\t\t\t2. Popularity Range" << endl;
    cout << "\n\t\t\t\tEnter your choice (1-2): ";
    option = getValidMenuChoice(1, 2);

    // Filter by Price Range
    if (option == 1) {
        int lowerPrice, upperPrice;
        cout << "\t\tEnter the lower price limit: ";
        lowerPrice = validatePrice();
        cout << "\t\tEnter the upper price limit: ";
        upperPrice = validatePrice();

        cout << "\nCars within price range Pkr" << lowerPrice << " to Pkr"
             << upperPrice << ":\n";
        cout << left;
        cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
             << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
             << "Status" << setw(25) << "Price" << endl;

        cout << setfill('-') << setw(90) << "-" << endl;
        cout << setfill(' ');

        for (int i = 0; i < size; i++) {
            if (invID[i] != -99 && invPrice[i] >= lowerPrice &&
                invPrice[i] <= upperPrice) {
                cout << setw(10) << invID[i] << setw(20) << invName[i]
                     << setw(15) << invModelYear[i] << setw(15)
                     << invPopRating[i] << setw(15) << invStatus[i] << setw(15)
                     << "Pkr" << invPrice[i] << endl;
            }
        }
    }
    // Filter by Popularity Range
    else if (option == 2) {
        int lowerPopularity, upperPopularity;
        cout << "\t\tEnter the lower popularity limit (0-9): ";
        lowerPopularity = validatePopularityRating();
        cout << "\t\tEnter the upper popularity limit (0-9): ";
        upperPopularity = validatePopularityRating();

        cout << "\nCars within popularity range " << lowerPopularity << " to "
             << upperPopularity << ":\n";
        cout << left;
        cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
             << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
             << "Status" << setw(25) << "Price" << endl;

        cout << setfill('-') << setw(90) << "-" << endl;
        cout << setfill(' ');

        for (int i = 0; i < size; i++) {
            if (invID[i] != -99 && invPopRating[i] >= lowerPopularity &&
                invPopRating[i] <= upperPopularity) {
                cout << setw(10) << invID[i] << setw(20) << invName[i]
                     << setw(15) << invModelYear[i] << setw(15)
                     << invPopRating[i] << setw(15) << invStatus[i] << setw(15)
                     << "Pkr" << invPrice[i] << endl;
            }
        }
    }
    // Invalid Choice
    else {
        cout << "\t\tInvalid choice! Please enter 1 or 2.\n";
    }
}
// Searching for Car
void searchInv(int invID[], string invName[], int invModelYear[],
               int invPopRating[], string invStatus[], int invPrice[],
               int size) {
    system("cls");
    cdmPrint();
    int choice;
    cout << "\n\t\t\tSearch Inventory by:" << endl;
    cout << "\t\t\t1. Car Name" << endl;
    cout << "\t\t\t2. Car ID" << endl;
    cout << "\t\t\t3. Model Year" << endl;
    cout << "\t\t\t4. Specific Price" << endl;
    cout << "\n\t\t\tEnter your choice (1-4): ";
    choice = getValidMenuChoice(1, 4);

    switch (choice) {
        case 1: {
            // Search by Car Name
            string searchName;
            cout << "\t\tEnter the Car Name to search: ";
            searchName = validateNameInput();

            cout << "\nCars matching the name \"" << searchName << "\":\n";
            cout << left;
            cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
                 << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
                 << "Status" << setw(15) << "Price " << endl;

            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');

            for (int i = 0; i < size; i++) {
                if (invID[i] != -99) {
                    bool match = false;

                    for (int j = 0;
                         j <= invName[i].length() - searchName.length(); j++) {
                        bool foundMatch = true;
                        for (int k = 0; k < searchName.length(); k++) {
                            if (invName[i][j + k] != searchName[k]) {
                                foundMatch = false;
                                break;
                            }
                        }
                        if (foundMatch) {
                            match = true;
                            break;
                        }
                    }
                    if (match) {
                        cout << setw(10) << invID[i] << setw(20) << invName[i]
                             << setw(15) << invModelYear[i] << setw(15)
                             << invPopRating[i] << setw(15) << invStatus[i]
                             << setw(15) << "PKR " << invPrice[i] << endl;
                    }
                }
            }
            break;
        }
        case 2: {
            // Search by Car ID
            int searchID;
            cout << "\t\tEnter the Car ID to search: ";
            searchID = validateID(size);

            cout << "\n\t\tCars matching the ID " << searchID << ":\n";
            cout << left;
            cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
                 << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
                 << "Status" << setw(15) << "Price " << endl;

            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');

            for (int i = 0; i < size; i++) {
                if (invID[i] != -99 && invID[i] == searchID) {
                    cout << setw(10) << invID[i] << setw(20) << invName[i]
                         << setw(15) << invModelYear[i] << setw(15)
                         << invPopRating[i] << setw(15) << invStatus[i]
                         << setw(15) << "PKR " << invPrice[i] << endl;
                }
            }
            break;
        }
        case 3: {
            // Search by Model Year
            int searchYear;
            cout << "\t\tEnter the Model Year to search: ";
            searchYear = validateModelYear();

            cout << "\n\t\tCars matching the Model Year " << searchYear
                 << ":\n";
            cout << left;
            cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
                 << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
                 << "Status" << setw(15) << "Price" << endl;

            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');

            for (int i = 0; i < size; i++) {
                if (invID[i] != -99 && invModelYear[i] == searchYear) {
                    cout << setw(10) << invID[i] << setw(20) << invName[i]
                         << setw(15) << invModelYear[i] << setw(15)
                         << invPopRating[i] << setw(15) << invStatus[i]
                         << setw(15) << "PKR " << invPrice[i] << endl;
                }
            }
            break;
        }
        case 4: {
            // Search by Specific Price
            int searchPrice;
            cout << "\t\tEnter the Price to search: ";
            searchPrice = validatePrice();

            cout << "\nCars matching the price  " << searchPrice << ":\n";
            cout << left;
            cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
                 << "Model Year" << setw(15) << "Pop. Rating" << setw(15)
                 << "Status" << setw(15) << "Price " << endl;

            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');

            for (int i = 0; i < size; i++) {
                if (invID[i] != -99 && invPrice[i] == searchPrice) {
                    cout << setw(10) << invID[i] << setw(20) << invName[i]
                         << setw(15) << invModelYear[i] << setw(15)
                         << invPopRating[i] << setw(15) << invStatus[i]
                         << setw(15) << "PKR " << invPrice[i] << endl;
                }
            }
            break;
        }
        default:
            cout << "\t\tInvalid choice! Please enter a number between 1 and "
                    "4.\n";
    }
}

// Base Functionalities for Client Menu of Manager

// List All Clients with their Attributes
void printClients(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size) {
    cout << left;
    cout << setw(15) << "Client ID" << setw(25) << "Name" << setw(25)
         << "Username" << setw(20) << "Contact No." << setw(20) << "Password"
         << endl;

    // Separator Line
    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        if (clientID[i] != -99) {
            cout << setw(15) << clientID[i] << setw(25) << clientName[i]
                 << setw(25) << clientUsername[i] << setw(20)
                 << clientContact[i] << setw(20) << clientPassword[i] << endl;
        }
    }
}

// Client Delition
bool deleteClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size) {
    int idToDelete;
    cout << "\n\t\tEnter the Client ID to delete: ";
    idToDelete = validateID(size);

    for (int i = 0; i < size; i++) {
        if (clientID[i] == idToDelete) {
            clientID[i] = -99;
            clientName[i] = "";
            clientUsername[i] = "";
            clientContact[i] = "";
            clientPassword[i] = "";

            cout << "\n\t\tClient with ID " << idToDelete
                 << " has been deleted successfully.\n";
            return true;
        }
    }

    cout << "\n\t\tClient ID not found. Deletion failed.\n";
    return false;
}
// Client Data Updatation
bool updateClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size) {
    int idToUpdate;
    cout << "\n\t\tEnter the Client ID to update: ";
    idToUpdate = validateID(size);

    for (int i = 0; i < size; i++) {
        if (clientID[i] == idToUpdate) {
            cout << "\n\t\tClient Found! What would you like to update?";
            cout << "\n\t\t1. Name\n\t\t2. Username\n\t\t3. Contact "
                    "Number\n\t\t4. Password\n";
            cout << "\n\t\t\tEnter your choice (1-4): ";
            int choice;
            choice = getValidMenuChoice(1, 4);

            switch (choice) {
                case 1: {
                    cout << "\n\t\tEnter new name: ";
                    cin.ignore();
                    clientName[i] = validateNameInput();
                    cout << "\n\t\tName updated successfully.\n";
                    break;
                }
                case 2: {
                    cout << "\n\t\tEnter new username: ";
                    cin >> clientUsername[i];
                    cout << "\n\t\tUsername updated successfully.\n";
                    break;
                }
                case 3: {
                    cout << "\n\t\tEnter new contact number: ";
                    clientContact[i] = validateContactNumber();
                    cout << "\n\t\tContact number updated successfully.\n";
                    break;
                }
                case 4: {
                    cout << "\n\t\tEnter new password: ";
                    clientPassword[i] = passwordValidator();
                    cout << "\n\t\tPassword updated successfully.\n";
                    break;
                }
                default:
                    cout << "\n\t\tInvalid choice. Update canceled.\n";
                    return false;
            }
            return true;
        }
    }

    // If Client ID is not found
    cout << "\n\t\tClient ID not found. Update failed.\n";
    return false;
}
// Searching Client
void searchClient(int clientID[], string clientName[], string clientUsername[],
                  string clientContact[], string clientPassword[], int size) {
    cout << "\n\t\tSearch Clients By:";
    cout << "\n\t\t1. Client ID\n\t\t2. Client Name";
    cout << "\n\t\t\tEnter your choice (1-2): ";
    int choice;
    choice = getValidMenuChoice(1, 2);

    switch (choice) {
        case 1: {
            int idToSearch;
            cout << "\n\t\tEnter the Client ID: ";
            idToSearch = validateID(size);

            bool found = false;
            for (int i = 0; i < size; i++) {
                if (clientID[i] == idToSearch) {
                    cout << "\n\t\tClient Found:";
                    cout << "\n\t\tClient ID   : " << clientID[i];
                    cout << "\n\t\tName        : " << clientName[i];
                    cout << "\n\t\tUsername    : " << clientUsername[i];
                    cout << "\n\t\tContact     : " << clientContact[i];
                    cout << "\n\t\tPassword    : " << clientPassword[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\n\t\tNo client found with the provided ID.\n";
            }
            break;
        }
        case 2: {
            string nameToSearch;
            cout << "\n\t\tEnter the Client Name: ";
            cin.ignore();
            nameToSearch = validateNameInput();

            bool found = false;
            cout << "\n\t\tSearch Results:";
            for (int i = 0; i < size; i++) {
                if (clientName[i] == nameToSearch) {
                    cout << "\n\t\tClient ID : " << clientID[i];
                    cout << "\n\t\tName      : " << clientName[i];
                    cout << "\n\t\tUsername  : " << clientUsername[i];
                    cout << "\n\t\tContact   : " << clientContact[i];
                    cout << "\n\t\tPassword  : " << clientPassword[i] << "\n";
                    found = true;
                }
            }
            if (!found) {
                cout << "\n\t\tNo client found with the provided name.\n";
            }
            break;
        }
        default:
            cout << "\n\t\tInvalid choice. Please try again.\n";
            break;
    }
}

// Filtering Client Functionality
void filterClientsForManager(int orderID[], int orderClientID[],
                             string orderStatus[], int clientID[],
                             string clientName[], string contactNumber[],
                             int size) {
    int choice;

    do {
        cout << "\n\n\t\t\tClient Filtering Menu\n";
        cout << "\t\t\t1. Filter Clients with Booked/Appointed Orders\n";
        cout << "\t\t\t2. Filter Clients with Completed Orders\n";
        cout << "\t\t\t0. Previous Menu\n";
        cout << "\n\t\t\tEnter your choice (0-2): ";
        choice = getValidMenuChoice(0, 2);

        switch (choice) {
            case 1: {  // Filter by Booked/ Appointed Orders
                cout << "\n\n\t\tClients with Booked/ Appointed Orders:\n";
                cout << "\t\t-----------------------------------------\n";
                bool found = false;

                for (int i = 0; i < size; i++) {
                    bool hasOrder = false;

                    for (int j = 0; j < size; j++) {
                        if (orderClientID[j] == clientID[i] &&
                            (orderStatus[j] == "Booked" ||
                             orderStatus[j] == "Appointed")) {
                            hasOrder = true;
                            found = true;
                            break;
                        }
                    }

                    if (hasOrder) {
                        cout << "\n\t\tClient ID     : " << clientID[i];
                        cout << "\n\t\tName          : " << clientName[i];
                        cout << "\n\t\tContact Number: " << contactNumber[i];
                        cout << "\n\t\t-------------------------------";
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo clients with booked or appointed orders "
                            "found.\n";
                }
                break;
            }

            case 2: {
                cout << "\n\n\t\tClients with Completed Orders:\n";
                cout << "\t\t---------------------------------\n";
                bool found = false;

                for (int i = 0; i < size; i++) {
                    bool hasCompletedOrder = false;

                    for (int j = 0; j < size; j++) {
                        if (orderClientID[j] == clientID[i] &&
                            orderStatus[j] == "Completed") {
                            hasCompletedOrder = true;
                            found = true;
                            break;
                        }
                    }

                    if (hasCompletedOrder) {
                        cout << "\n\t\tClient ID     : " << clientID[i];
                        cout << "\n\t\tName          : " << clientName[i];
                        cout << "\n\t\tContact Number: " << contactNumber[i];
                        cout << "\n\t\t-------------------------------";
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo clients with completed orders found.\n";
                }
                break;
            }

            default: {
                cout << "\n\t\tInvalid choice! Please try again.\n";
                break;
            }
        }

        // Pause to allow the manager to review the output
        cout << "\n\t\tPress any key to continue...";
        getch();

    } while (choice != 0);
}

// View All Query Functionality
void manageAllComplaints(int complaintID[], int complaintClientID[],
                         string complaintDetails[], string complaintReply[],
                         string clientName[], int size) {
    int choice;

    do {
        // Menu for Manager
        system("cls");
        cout << "\n\n\t\tComplaint Management Menu (Manager)\n";
        cout << "\t\t-------------------------------------\n";
        cout << "\t\t1. View All Complaints\n";
        cout << "\t\t2. Delete a Complaint\n";
        cout << "\t\t0. Return to Previous Menu\n";
        cout << "\n\t\t\tEnter your choice (0-2): ";
        choice = getValidMenuChoice(0, 2);

        switch (choice) {
            case 1: {  // View all complaints
                system("cls");
                cout << "\n\n\t\tAll Complaints\n";
                cout << "\t\t-------------------------------------\n";
                bool found = false;

                for (int i = 0; i < size; i++) {
                    if (complaintID[i] != -99) {  // Valid complaint
                        found = true;
                        cout << "\n\t\tComplaint ID: " << complaintID[i];
                        cout << "\n\t\tClient ID: " << complaintClientID[i];

                        // Find and display the client's name
                        string name = "Unknown";
                        for (int j = 0; j < size; j++) {
                            if (complaintClientID[i] == j &&
                                clientName[j] != "") {
                                name = clientName[j];
                                break;
                            }
                        }
                        cout << "\n\t\tClient Name: " << name;

                        // Display complaint details and reply
                        cout << "\n\t\tComplaint Details: "
                             << complaintDetails[i];
                        if (!complaintReply[i].empty()) {
                            cout << "\n\t\tReply: " << complaintReply[i];
                        } else {
                            cout << "\n\t\tReply: No reply yet.";
                        }
                        cout << "\n\t\t-------------------------------------";
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo complaints available.\n";
                }

                cout << "\n\t\tPress any key to return to the menu...";
                getch();
                break;
            }

            case 2: {  // Delete a complaint
                system("cls");
                cout << "\n\n\t\tDelete a Complaint\n";
                cout << "\t\t-------------------------------------\n";

                int deleteID;
                cout << "\t\tEnter the Complaint ID to delete: ";
                deleteID = validateID(size);

                bool found = false;
                for (int i = 0; i < size; i++) {
                    if (complaintID[i] == deleteID) {  // Match found
                        found = true;

                        // Delete the complaint
                        complaintID[i] = -99;
                        complaintClientID[i] = -99;
                        complaintDetails[i] = "";
                        complaintReply[i] = "";

                        cout << "\n\t\tComplaint with ID " << deleteID
                             << " has been deleted.";
                        break;
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo complaint found with ID " << deleteID
                         << ".\n";
                }

                cout << "\n\t\tPress any key to return to the menu...";
                getch();
                break;
            }

            default:
                cout << "\n\t\tInvalid choice! Please try again.\n";
                getch();
                break;
        }
    } while (choice != 0);
}

// Reply to Query Functionality
void replyToComplaint(int complaintID[], string complaintDetails[],
                      string complaintReply[], int size) {
    int inputComplaintID;
    cout << "\n\n\t\tReply to Complaint\n";
    cout << "\t\t--------------------\n";
    cout << "\t\tEnter Complaint ID to reply: ";
    inputComplaintID = validateID(size);

    bool found = false;

    for (int i = 0; i < size; i++) {
        if (complaintID[i] == inputComplaintID) {
            found = true;
            cout << "\n\t\tComplaint Details: " << complaintDetails[i];
            cout << "\n\t\tEnter your reply: ";
            cin.ignore();
            getline(cin, complaintReply[i]);
            cout << "\n\t\tReply added successfully!";
            break;
        }
    }

    if (!found) {
        cout << "\n\t\tComplaint ID not found! Please try again.";
    }
    cout << "\n\t\tPress any key to return to the previous menu...";
    getch();
}

// View All Suggestion Functionality
void manageSuggestions(int suggestionID[], int suggestionClientID[],
                       string suggestionDetails[], int size) {
    int choice;

    do {
        // Menu for managing suggestions
        system("cls");
        cout << "\n\n\t\tSuggestion Management Menu\n";
        cout << "\t\t--------------------------------\n";
        cout << "\t\t1. View All Suggestions\n";
        cout << "\t\t2. Delete a Suggestion\n";
        cout << "\t\t0. Return to Previous Menu\n";
        cout << "\n\t\t\tEnter your choice (0-2): ";
        choice = getValidMenuChoice(0, 2);

        switch (choice) {
            case 1: {  // View all suggestions
                system("cls");
                cout << "\n\n\t\tAll Client Suggestions\n";
                cout << "\t\t--------------------------------\n";
                bool found = false;

                for (int i = 0; i < size; i++) {
                    if (suggestionID[i] != -99) {  // Valid suggestion
                        found = true;
                        cout << "\n\t\tSuggestion ID: " << suggestionID[i];
                        cout << "\n\t\tClient ID: " << suggestionClientID[i];
                        cout << "\n\t\tSuggestion Details: "
                             << suggestionDetails[i];
                        cout << "\n\t\t--------------------------------\n";
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo suggestions available at the moment.\n";
                }

                cout << "\n\t\tPress any key to return to the menu...";
                getch();
                break;
            }

            case 2: {  // Delete a suggestion
                system("cls");
                cdmPrint();
                cout << "\n\n\t\tDelete a Suggestion\n";
                cout << "\t\t--------------------------------\n";

                int deleteID;
                cout << "\t\tEnter the Suggestion ID to delete: ";
                deleteID = validateID(size);

                bool found = false;
                for (int i = 0; i < size; i++) {
                    if (suggestionID[i] == deleteID) {  // Match found
                        found = true;

                        // Clear suggestion data
                        suggestionID[i] = -99;
                        suggestionClientID[i] = -99;
                        suggestionDetails[i] = "";

                        cout << "\n\t\tSuggestion with ID " << deleteID
                             << " has been deleted.\n";
                        break;
                    }
                }

                if (!found) {
                    cout << "\n\t\tNo suggestion found with ID " << deleteID
                         << ".\n";
                }

                cout << "\n\t\tPress any key to return to the menu...";
                getch();
                break;
            }

            default:
                cout << "\n\t\tInvalid choice! Please try again.\n";
                getch();
                break;
        }
    } while (choice != 0);
}

// BAse Functionalities For Order Management

// View All Orders
void viewAllOrders(int orderID[], int orderClientID[], int orderCarID[],
                   string orderStatus[], string orderDate[],
                   string appointmentDate[], string appointmentTime[],
                   int size) {
    system("cls");
    cdmPrint();
    cout << "\n\n\t\tAll Client Orders\n";
    cout << "\t\t-----------------------------------------------\n";
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (orderID[i] != -99) {  // Valid order
            found = true;

            cout << "\n\t\tOrder ID: " << orderID[i];
            cout << "\n\t\tClient ID: " << orderClientID[i];
            cout << "\n\t\tCar ID: " << orderCarID[i];
            cout << "\n\t\tOrder Status: " << orderStatus[i];
            if (orderStatus[i] == "Completed")
                cout << "\n\t\tSold Date: " << orderDate[i];
            else
                cout << "\n\t\tOrder Date: " << orderDate[i];

            if (orderStatus[i] == "Appointed") {
                cout << "\n\t\tAppointment Date: " << appointmentDate[i];
                cout << "\n\t\tAppointment Time: " << appointmentTime[i];
            } else {
                cout << "\n\t\tAppointment: Not Applicable";
            }

            cout << "\n\t\t-----------------------------------------------";
        }
    }

    if (!found) {
        cout << "\n\t\tNo orders available at the moment.\n";
    }

    cout << "\n\t\tPress any key to return to the previous menu...";
    getch();
}
// Approving orders by changing their state and Cars State
void approveOrder(int orderID[], int orderClientID[], int orderCarID[],
                  string orderStatus[], string orderDate[],
                  string appointmentDate[], string appointmentTime[],
                  string invStatus[], int invID[], string saleDates[],
                  int size) {
    system("cls");
    cout << "\n\n\t\tApprove Order\n";
    cout << "\t\t-----------------------------------------------\n";

    int approveID;
    cout << "\t\tEnter the Order ID you want to approve: ";
    approveID = validateID(size);

    bool found = false;

    for (int i = 0; i < size; i++) {
        if (orderID[i] == approveID) {
            found = true;

            cout << "\n\t\tOrder Found!";
            cout << "\n\t\tOrder ID: " << orderID[i];
            cout << "\n\t\tClient ID: " << orderClientID[i];
            cout << "\n\t\tCar Inventory ID: " << orderCarID[i];
            cout << "\n\t\tOrder Status: " << orderStatus[i];
            cout << "\n\t\t-----------------------------------------------\n";

            cout << "\n\t\tWhat would you like to do with this order?\n";
            cout << "\t\t1. Mark as Completed (Car Sold)\n";
            cout << "\t\t2. Assign Appointment Date and Time\n";
            cout << "\n\t\t\tEnter your choice (1-2): ";
            int choice;
            choice = getValidMenuChoice(1, 2);

            if (choice == 1) {
                cout << "\n\t\tEnter the date of sale (YYYY-MM-DD): ";
                saleDates[i] = validateDate();
                orderStatus[i] = "Completed";

                for (int j = 0; j < size; j++) {
                    if (invID[j] == orderCarID[i]) {
                        invStatus[j] = "Sold";
                        break;
                    }
                }

                cout << "\n\t\tOrder ID " << approveID
                     << " has been marked as Completed.\n";
                cout << "\t\tCar Inventory ID " << orderCarID[i]
                     << " status updated to Sold.\n";

            } else if (choice == 2) {
                cout << "\n\t\tEnter the appointment date (YYYY-MM-DD): ";
                appointmentDate[i] = validateDate();
                cout << "\t\tEnter the appointment time (HH:MM): ";
                appointmentTime[i] = validateTime();
                orderStatus[i] = "Appointed";

                for (int j = 0; j < size; j++) {
                    if (invID[j] == orderCarID[i]) {
                        invStatus[j] = "Appointed";
                        break;
                    }
                }

                cout << "\n\t\tAppointment for Order ID " << approveID
                     << " has been set.\n";
                cout << "\t\tCar Inventory ID " << orderCarID[i]
                     << " status updated to Appointed.\n";

            } else {
                cout << "\n\t\tInvalid choice! Returning to menu...\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "\n\t\tNo order found with ID " << approveID << ".\n";
    }

    cout << "\n\t\tPress any key to return to the previous menu...";
    getch();
}
// Base Functionalities for Sales Management For Manager

// Printing All Sales
void printAllSales(int orderID[], int orderClientID[], int orderCarID[],
                   string orderStatus[], int invID[], string invName[],
                   int invPrice[], string saleDates[], int generalDBSize) {
    system("cls");
    cdmPrint();
    cout << "\n\t\t--- Sales Records ---\n";
    cout << left << setw(10) << "Order ID" << setw(10) << "Client ID"
         << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Price" << setw(15) << "Sale Date" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << setfill(' ');

    bool hasSales = false;

    for (int i = 0; i < generalDBSize; i++) {
        if (orderStatus[i] == "Completed") {
            hasSales = true;

            bool carFound = false;
            for (int j = 0; j < generalDBSize; j++) {
                if (invID[j] == orderCarID[i]) {
                    carFound = true;
                    cout << setw(10) << orderID[i] << setw(10)
                         << orderClientID[i] << setw(10) << invID[j] << setw(20)
                         << invName[j] << setw(15) << invPrice[j] << setw(15)
                         << saleDates[i] << endl;
                    break;
                }
            }

            if (!carFound) {
                cout << setw(10) << orderID[i] << setw(10) << orderClientID[i]
                     << setw(10) << orderCarID[i] << setw(20) << "Unknown"
                     << setw(15) << "Unknown" << setw(15) << saleDates[i]
                     << endl;
            }
        }
    }

    if (!hasSales) {
        system("cls");
        cdmPrint();
        cout << "\n\t\tNo Sales Records Found!" << endl;
    }

    cout << "\n\t\tPress Any Key to Return to the Previous Menu...";
    getch();
}
// Seaching a Sale By Date
void filterSalesByDate(int orderID[], int orderClientID[], int orderCarID[],
                       string orderStatus[], int invID[], string invName[],
                       int invPrice[], string saleDates[], int generalDBSize) {
    system("cls");
    cout << "\n\t\t--- Filter Sales by Date ---\n";

    string targetDate;
    cout << "\t\tEnter the Sale Date (e.g., 2024-12-01): ";
    targetDate = validateDate();

    cout << left << setw(10) << "Order ID" << setw(10) << "Client ID"
         << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Price" << setw(15) << "Sale Date" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << setfill(' ');

    bool found = false;

    for (int i = 0; i < generalDBSize; i++) {
        if (orderStatus[i] == "Completed" && saleDates[i] == targetDate) {
            found = true;

            bool carFound = false;
            for (int j = 0; j < generalDBSize; j++) {
                if (invID[j] == orderCarID[i]) {
                    carFound = true;
                    cout << setw(10) << orderID[i] << setw(10)
                         << orderClientID[i] << setw(10) << invID[j] << setw(20)
                         << invName[j] << setw(15) << invPrice[j] << setw(15)
                         << saleDates[i] << endl;
                    break;
                }
            }

            if (!carFound) {
                cout << setw(10) << orderID[i] << setw(10) << orderClientID[i]
                     << setw(10) << orderCarID[i] << setw(20) << "Unknown"
                     << setw(15) << "Unknown" << setw(15) << saleDates[i]
                     << endl;
            }
        }
    }

    if (!found) {
        system("cls");
        cdmPrint();
        cout << "\n\t\tNo Sales Found for the Given Date!" << endl;
    }

    cout << "\n\t\tPress Any Key to Return to the Previous Menu...";
    getch();
}
// Deleteing a Sale By Sale ID
void deleteSale(int orderID[], string orderStatus[], string saleDates[],
                int invID[], string invStatus[], int generalDBSize) {
    int orderToDelete;
    cout << "\nEnter the Order ID of the sale to delete: ";
    orderToDelete = validateID(generalDBSize);

    bool found = false;
    for (int i = 0; i < generalDBSize; i++) {
        if (orderID[i] == orderToDelete && orderStatus[i] == "Completed") {
            found = true;
            cout << "\nSale found. Are you sure you want to delete this sale? "
                    "(This action cannot be undone.) (y/n): ";

            char confirmation;
            confirmation = validateYesNoInput();

            if (confirmation == 'y' || confirmation == 'Y') {
                orderStatus[i] = "Cancelled";
                saleDates[i] = "";

                invStatus[invID[i]] = "Available";

                cout << "\nSale with Order ID " << orderToDelete
                     << " has been cancelled.\n";
                cout << "Car status has been updated to 'Available'.\n";

                break;
            } else {
                cout << "\nSale deletion cancelled.\n";
                break;
            }
        }
    }

    if (!found) {
        cout << "\nSale with Order ID " << orderToDelete
             << " not found or not completed yet.\n";
    }
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}

// Profile Setting Functionalities For Manager
void manageManagerSettings(string& managerSecurityQuestion,
                           string& managerSecurityAnswer,
                           string& managerUserName, string& managerPassword) {
    int choice;
    do {
        system("cls");
        cdmPrint();
        cout << "\n\n\t\tManager Settings Menu\n";
        cout << "\t\t----------------------------\n";
        cout << "\t\t1. Change Username\n";
        cout << "\t\t2. Change Password\n";
        cout << "\t\t3. Set Security Question & Answer\n";
        cout << "\t\t0. Exit\n";
        cout << "\n\t\t\tEnter your choice (0-3): ";
        choice = getValidMenuChoice(0, 3);

        switch (choice) {
            case 1: {
                cout << "\n\t\tEnter new Username: ";
                getline(cin, managerPassword);
                cout << "\n\t\tUsername successfully updated!\n";
                break;
            }

            case 2: {
                cout << "\n\t\tEnter new Password: ";
                managerPassword = passwordValidator();
                cout << "\n\t\tPassword successfully updated!\n";
                break;
            }

            case 3: {
                cout << "\n\t\tEnter new Security Question: ";
                cin.ignore();
                getline(cin, managerSecurityQuestion);
                cout << "\t\tEnter new Security Answer: ";
                getline(cin, managerSecurityAnswer);
                cout << "\n\t\tSecurity Question and Answer successfully "
                        "updated!\n";
                break;
            }
            case 0:
                break;

            default: {
                cout << "\n\t\tInvalid choice! Please try again.\n";
                break;
            }
        }
        if (choice != 0) {
            cout << "\t\tPress Any Key to Move Back TO Previous menu";
            getch();
        }

    } while (choice != 0);
    cout << "\t\tPress Any Key to Move Back TO Managers Main Menu";
    getch();
}

// Client Related Functionalities

// Base Functionalities of Client Inventory Menu

// Print all Cars Available
void printCarsForClient(int invID[], string invName[], int invModelYear[],
                        int invPopRating[], string invStatus[], int invPrice[],
                        int size) {
    cout << left;
    cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Model Year" << setw(15) << "Pop. Rating" << setw(15) << "Status"
         << setw(25) << "Price" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');

    bool carsAvailable = false;

    for (int i = 0; i < size; i++) {
        if (invID[i] != -99) {
            string carStatus = invStatus[i];

            if (carStatus == "Available") {
                cout << setw(10) << invID[i] << setw(20) << invName[i]
                     << setw(15) << invModelYear[i] << setw(15)
                     << invPopRating[i] << setw(15) << "Available" << setw(15)
                     << invPrice[i] << " Pkr" << endl;
                carsAvailable = true;
            } else if (carStatus == "Not Available") {
                cout << setw(10) << invID[i] << setw(20) << invName[i]
                     << setw(15) << invModelYear[i] << setw(15)
                     << invPopRating[i] << setw(15) << "Not Available"
                     << setw(15) << invPrice[i] << " Pkr" << endl;
            } else if (carStatus == "Booked") {
                cout << setw(10) << invID[i] << setw(20) << invName[i]
                     << setw(15) << invModelYear[i] << setw(15)
                     << invPopRating[i] << setw(15) << "Booked" << setw(15)
                     << invPrice[i] << " Pkr" << endl;
            }
        }
    }

    if (!carsAvailable) {
        cout << "\n\tNo cars available to display at the moment.\n";
    }
    cout << "\t\tPress Any Key to Move Back To Previous Menu";
    getch();
}

// Filtering Cars By Price
void filterCarsByPrice(int invID[], string invName[], int invModelYear[],
                       int invPopRating[], string invStatus[], int invPrice[],
                       int size) {
    int lowerPrice, upperPrice;
    bool carFound = false;

    cout << "\n\t\tEnter the Lower Price Limit: ";
    lowerPrice = validatePrice();

    cout << "\t\tEnter the Upper Price Limit: ";
    upperPrice = validatePrice();

    cout << left;
    cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Model Year" << setw(15) << "Pop. Rating" << setw(15) << "Status"
         << setw(25) << "Price" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;

    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        if (invPrice[i] >= lowerPrice && invPrice[i] <= upperPrice &&
            invStatus[i] == "Available") {
            carFound = true;
            cout << setw(10) << invID[i] << setw(20) << invName[i] << setw(15)
                 << invModelYear[i] << setw(15) << invPopRating[i] << setw(15)
                 << invStatus[i] << setw(15) << invPrice[i] << " Pkr" << endl;
        }
    }
    if (carFound) {
        cout << "\t\tPress Any Key To Move Back to Previous Menu";
        getch();
    }

    // If no cars found within the specified price range
    if (!carFound) {
        system("cls");
        cdmPrint();
        cout << "\n\n\t\tNo cars available in the given price range." << endl;
        cout << "\t\tPress Any Key To Move Back to Previous Menu";
        getch();
    }
}

// Filtering Cars By Popularity
void filterCarsByPopularity(int invID[], string invName[], int invModelYear[],
                            int invPopRating[], string invStatus[],
                            int invPrice[], int size) {
    int lowerPop, upperPop;
    bool carFound = false;

    cout << "\n\t\tEnter the Lower Popularity Limit (0-9): ";
    lowerPop = validatePopularityRating();

    cout << "\t\tEnter the Upper Popularity Limit (0-9): ";
    upperPop = validatePopularityRating();
    // Here I will validate Popularity

    cout << left;
    cout << setw(10) << "Car ID" << setw(20) << "Car Name" << setw(15)
         << "Model Year" << setw(15) << "Pop. Rating" << setw(15) << "Status"
         << setw(25) << "Price" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;

    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        if (invPopRating[i] >= lowerPop && invPopRating[i] <= upperPop &&
            invStatus[i] == "Available") {
            carFound = true;
            cout << setw(10) << invID[i] << setw(20) << invName[i] << setw(15)
                 << invModelYear[i] << setw(15) << invPopRating[i] << setw(15)
                 << invStatus[i] << setw(15) << invPrice[i] << " Pkr" << endl;
        }
    }

    if (carFound) {
        cout << "\t\tPress Any Key To Move Back to Previous Menu";
        getch();
    }

    // If no cars found within the specified price range
    if (!carFound) {
        system("cls");
        cdmPrint();
        cout << "\n\n\t\tNo cars available in the given popularity range."
             << endl;
        cout << "\t\tPress Any Key To Move Back to Previous Menu";
        getch();
    }
}

// Base Functionalities For Ordering a Car

// Client Searching for a Car
void searchAvailableCars(int invID[], string invName[], int invModelYear[],
                         int invPopRating[], string invStatus[], int invPrice[],
                         int size) {
    int choice;
    cout << "\n\t\tSearch Available Cars By:\n";
    cout << "\t\t1. Car ID\n";
    cout << "\t\t2. Car Name\n";
    cout << "\n\t\t\tEnter your choice (1-2): ";
    choice = getValidMenuChoice(1, 2);

    bool found = false;
    switch (choice) {
        case 1: {
            int carID;
            cout << "\n\t\tEnter Car ID: ";
            carID = validateID(size);

            for (int i = 0; i < size; i++) {
                if (invID[i] == carID && invStatus[i] == "Available") {
                    cout << "\n\t\tCar Found!\n";
                    cout << "\t\tCar ID: " << invID[i] << endl;
                    cout << "\t\tCar Name: " << invName[i] << endl;
                    cout << "\t\tModel Year: " << invModelYear[i] << endl;
                    cout << "\t\tPopularity Rating: " << invPopRating[i]
                         << endl;
                    cout << "\t\tPrice: " << invPrice[i] << " Pkr" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\n\t\tNo Available Car Found with ID " << carID
                     << ".\n";
            }
            break;
        }
        case 2: {
            string carName;
            cout << "\n\t\tEnter Car Name: ";
            carName = validateNameInput();

            for (int i = 0; i < size; i++) {
                if (invName[i] == carName && invStatus[i] == "Available") {
                    cout << "\n\t\tCar Found!\n";
                    cout << "\t\tCar ID: " << invID[i] << endl;
                    cout << "\t\tCar Name: " << invName[i] << endl;
                    cout << "\t\tModel Year: " << invModelYear[i] << endl;
                    cout << "\t\tPopularity Rating: " << invPopRating[i]
                         << endl;
                    cout << "\t\tPrice: " << invPrice[i] << " Pkr" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "\n\t\tNo Available Car Found with Name \"" << carName
                     << "\".\n";
            }
            break;
        }
        default:
            cout << "\n\t\tInvalid Choice. Please try again.\n";
            break;
    }
    cout << "\t\tPlease Enter a Key to Move Back To Previous Menu";
    getch();
}
// Clients Order Placing
bool placeOrder(int orderID[], int orderClientID[], int orderCarID[],
                string orderStatus[], string orderDate[], int clientID,
                int invID[], string invName[], string invStatus[],
                const int generalDBSize) {
    if (checkSpaceInt(orderID, generalDBSize)) {
        int carID;
        cout << "\n\t\tEnter the Car ID you want to book: ";
        carID = validateID(generalDBSize);

        int carIndex = -1;
        for (int i = 0; i < generalDBSize; i++) {
            if (invID[i] != -99 && invID[i] == carID &&
                invStatus[i] == "Available") {
                carIndex = i;
                break;
            }
        }

        if (carIndex == -1) {
            cout << "\n\t\tCar ID not found or the car is not available for "
                    "booking.\n";
            cout << "\n\t\tPlease Enter a Key to Move Back To Previous Menu";
            getch();
            return false;
        }

        cout << "\n\t\tCar Found! Details:\n";
        cout << "\t\tCar ID: " << invID[carIndex] << endl;
        cout << "\t\tCar Name: " << invName[carIndex] << endl;

        cout << "\n\t\tDo you want to confirm the order? (Y/N): ";
        char choice;
        choice = validateYesNoInput();

        if (toupper(choice) == 'Y') {
            int orderIndex = outputEmptyIndexInt(orderID, generalDBSize);
            if (orderIndex == -1) {
                cout << "\n\t\tNo space available to place the order.\n";
                cout
                    << "\n\t\tPlease Enter a Key to Move Back To Previous Menu";
                getch();
                return false;
            }

            // Place the order
            orderID[orderIndex] = orderIndex;
            orderClientID[orderIndex] = clientID;
            orderCarID[orderIndex] = invID[carIndex];
            orderStatus[orderIndex] = "Booked";
            invStatus[carIndex] = "Booked";

            cout << "\t\tEnter Order Date (YYYY-MM-DD): ";
            orderDate[orderIndex] = validateDate();

            cout << "\n\t\tOrder placed successfully with Order ID: "
                 << orderID[orderIndex] << endl;
            cout << "\n\t\tPlease Enter a Key to Move Back To Previous Menu";
            getch();
            return true;
        } else {
            cout << "\n\t\tOrder not confirmed.\n";
            cout << "\n\t\tPlease Enter a Key to Move Back To Previous Menu";
            getch();
            return false;
        }
    } else {
        cout << "\n\t\tNo space available to add a new order.\n";
        cout << "\n\t\tPlease Enter a Key to Move Back To Previous Menu";
        getch();
        return false;
    }
}

// Base Functionalities for Order Stats Menu

// Print Current Orders
void printClientCurrentOrders(int orderID[], int orderClientID[],
                              int orderCarID[], string orderStatus[],
                              string appointmentDate[],
                              string appointmentTime[], int invID[],
                              string invName[], int invPrice[], int size,
                              int& loggedInClientID) {
    bool hasOrders = false;

    cout << "\n\t\t--- Current Orders (Booked or Appointed) ---\n";
    cout << left << setw(10) << "Order ID" << setw(10) << "Car ID" << setw(20)
         << "Car Name" << setw(15) << "Price" << setw(15) << "Status"
         << setw(15) << "App. Date" << setw(15) << "App. Time" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        if (orderClientID[i] == loggedInClientID &&
            (orderStatus[i] == "Booked" || orderStatus[i] == "Appointed")) {
            hasOrders = true;
            int carIndex = orderCarID[i];
            cout << setw(10) << orderID[i] << setw(10) << invID[carIndex]
                 << setw(20) << invName[carIndex] << setw(15)
                 << invPrice[carIndex] << setw(15) << orderStatus[i];

            if (orderStatus[i] == "Appointed") {
                cout << setw(15) << appointmentDate[i] << setw(15)
                     << appointmentTime[i];
            } else {
                cout << setw(15) << "N/A" << setw(15) << "N/A";
            }
            cout << endl;
        }
    }

    if (!hasOrders) {
        cout << "\n\t\tNo Current Orders Found!" << endl;
    }
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}
// Print Compeleted Orders
void printClientCompletedOrders(int orderID[], int orderClientID[],
                                int orderCarID[], string orderStatus[],
                                int invID[], string invName[], int invPrice[],
                                int generalDBSize, int& loggedInClientID) {
    bool hasOrders = false;

    system("cls");
    cout << "\n\t\t--- Completed Orders (Sold) ---\n";
    cout << left << setw(10) << "Order ID" << setw(10) << "Car ID" << setw(20)
         << "Car Name" << setw(15) << "Price" << endl;

    cout << setfill('-') << setw(60) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < generalDBSize; i++) {
        if (orderClientID[i] == loggedInClientID &&
            orderStatus[i] == "Completed") {
            hasOrders = true;

            // Find car details in the inventory using orderCarID
            bool carFound = false;
            for (int j = 0; j < generalDBSize; j++) {
                if (invID[j] == orderCarID[i]) {
                    carFound = true;
                    cout << setw(10) << orderID[i] << setw(10) << invID[j]
                         << setw(20) << invName[j] << setw(15) << invPrice[j]
                         << endl;
                    break;
                }
            }

            if (!carFound) {
                cout << setw(10) << orderID[i] << setw(10) << orderCarID[i]
                     << setw(20) << "Unknown" << setw(15) << "Unknown" << endl;
            }
        }
    }

    if (!hasOrders) {
        cout << "\n\t\tNo Completed Orders Found!" << endl;
    }

    cout << "\n\t\tPress Any Key to Move Back to the Previous Menu...";
    getch();
}

// Delete Any of clients Current Order
void deleteCurrentClientOrder(int orderID[], int orderClientID[],
                              int orderCarID[], string orderStatus[],
                              string appointmentDate[],
                              string appointmentTime[], int generalDBSize,
                              int& loggedInClientID) {
    int orderIDToDelete;
    bool orderFound = false;

    cout << "\n\t\tEnter the Order ID you wish to delete: ";
    orderIDToDelete = validateID(generalDBSize);

    for (int i = 0; i < generalDBSize; i++) {
        if (orderID[i] == orderIDToDelete &&
            orderClientID[i] == loggedInClientID) {
            orderFound = true;

            char confirmation;
            cout << "\n\t\tOrder found: Car ID: " << orderCarID[i]
                 << ", Status: " << orderStatus[i] << endl;
            cout << "\n\t\tAre you sure you want to delete this order? (Y/N): ";
            confirmation = validateYesNoInput();

            if (confirmation == 'Y' || confirmation == 'y') {
                orderID[i] = -99;
                orderClientID[i] = -99;
                orderCarID[i] = -99;
                orderStatus[i] = "";
                appointmentDate[i] = "";
                appointmentTime[i] = "";

                cout << "\n\t\tOrder has been successfully deleted." << endl;
                break;
            } else {
                cout << "\n\t\tOrder deletion canceled." << endl;
                break;
            }
        }
    }

    if (!orderFound) {
        cout << "\n\t\tNo such order exists for your Client ID or Order ID is "
                "incorrect."
             << endl;
    }
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}

// Base Functionalities For Client Compaint System

// Adding a Complaint
void submitComplaint(int complaintID[], int complaintClientID[],
                     string complaintDetails[], string complaintReply[],
                     int generalDBSize, int& loggedInClientID) {
    int complaintIndex = -1;

    // Check if there is space for a new complaint
    for (int i = 0; i < generalDBSize; i++) {
        if (complaintID[i] == -99) {
            complaintIndex = i;
            break;
        }
    }

    if (complaintIndex == -1) {
        cout << "\n\t\tSorry, the complaint database is full." << endl;
        cout << "\t\tPress Any Key to Move Back TO Previous menu";
        getch();
        return;
    }

    string complaintText;
    cout << "\n\t\tEnter your complaint: ";
    getline(cin, complaintText);

    complaintID[complaintIndex] = complaintIndex;
    complaintClientID[complaintIndex] = loggedInClientID;
    complaintDetails[complaintIndex] = complaintText;
    complaintReply[complaintIndex] = "";

    cout << "\n\t\tYour complaint has been successfully submitted!" << endl;
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}
// View Replies Of Submitted Complaint
void viewComplaintsAndReplies(int complaintID[], int complaintClientID[],
                              string complaintDetails[],
                              string complaintReply[], int generalDBSize,
                              int& loggedInClientID) {
    bool hasComplaints = false;

    cout << "\n\t\tYour Complaints and Replies:\n";
    for (int i = 0; i < generalDBSize; i++) {
        if (complaintClientID[i] == loggedInClientID && complaintID[i] != -99) {
            hasComplaints = true;
            cout << "\n\t\tComplaint ID: " << complaintID[i] << endl;
            cout << "\n\t\tComplaint Details: " << complaintDetails[i] << endl;

            // Check if a reply exists
            if (complaintReply[i] != "") {
                cout << "\n\t\tManager's Reply: " << complaintReply[i] << endl;
            } else {
                cout << "\n\t\tNo reply yet from the manager." << endl;
            }
            cout << "------------------------------------------\n";
        }
    }

    if (!hasComplaints) {
        cout << "\n\t\tYou haven't submitted any complaints yet." << endl;
    }
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}
// Deleting Complaint
void deleteComplaint(int complaintID[], int complaintClientID[],
                     string complaintDetails[], string complaintReply[],
                     int& loggedInClientID, int generalDBSize) {
    int complaintIDToDelete;
    bool complaintFound = false;

    cout << "\n\t\tEnter the Complaint ID you wish to delete: ";
    complaintIDToDelete = validateID(generalDBSize);

    for (int i = 0; i < generalDBSize; i++) {
        if (complaintID[i] == complaintIDToDelete &&
            complaintClientID[i] == loggedInClientID) {
            complaintFound = true;

            complaintID[i] = -99;
            complaintClientID[i] = -99;
            complaintDetails[i] = "";
            complaintReply[i] = "";

            cout << "\n\t\tComplaint ID " << complaintIDToDelete
                 << " has been deleted successfully." << endl;
            break;
        }
    }

    if (!complaintFound) {
        // If no matching complaint was found
        cout << "\n\t\tNo complaint found with the provided Complaint ID, or "
                "it does not belong to you."
             << endl;
    }
    cout << "\n\t\tPress any key to continue...";
    getch();
}

// Base Functionalities For Client Suggestion Submission System
// Submitting a Suggestion
void submitSuggestion(int suggestionID[], int suggestionClientID[],
                      string suggestionDetails[], int& loggedInClientID,
                      int size) {
    bool slotFound = false;

    for (int i = 0; i < size; i++) {
        if (suggestionID[i] == -99) {
            suggestionID[i] = i;  // Assign a new ID
            suggestionClientID[i] = loggedInClientID;

            cout << "\n\t\tEnter your suggestion details: ";
            cin.ignore();
            getline(cin, suggestionDetails[i]);

            cout << "\n\t\tSuggestion submitted successfully with ID: "
                 << suggestionID[i] << "\n";
            slotFound = true;
            break;
        }
    }

    if (!slotFound) {
        cout << "\n\t\tNo space available for new suggestions. Please delete "
                "old suggestions to add new ones.\n";
    }
    cout << "\t\tPress Any Key to Move Back TO Previous menu";
    getch();
}

// Delete Suggeston
void deleteSuggestion(int suggestionID[], int suggestionClientID[],
                      string suggestionDetails[], int& loggedInClientID,
                      int maxSize) {
    cout << "\n\t\tYour Suggestions:\n";
    cout << "\t\t-----------------------------\n";

    bool found = false;

    for (int i = 0; i < maxSize; i++) {
        if (suggestionClientID[i] == loggedInClientID &&
            suggestionID[i] != -99) {
            found = true;
            cout << "\t\tSuggestion ID: " << suggestionID[i] << "\n";
            cout << "\t\tDetails: " << suggestionDetails[i] << "\n";
            cout << "\t\t-----------------------------\n";
        }
    }

    if (!found) {
        cout << "\n\t\tYou have no suggestions to delete.\n";
        cout << "\t\tPress Any Key to Move Back TO Previous menu";
        getch();
        return;
    }

    int deleteID;
    cout << "\n\t\tEnter the Suggestion ID to delete: ";
    deleteID = validateID(maxSize);

    found = false;

    for (int i = 0; i < maxSize; i++) {
        if (suggestionID[i] == deleteID &&
            suggestionClientID[i] == loggedInClientID) {
            found = true;

            // Clear the suggestion
            suggestionID[i] = -99;
            suggestionClientID[i] = -99;
            suggestionDetails[i] = "";

            cout << "\n\t\tSuggestion with ID " << deleteID
                 << " has been deleted.\n";
            break;
        }
    }

    if (!found) {
        cout << "\n\t\tInvalid Suggestion ID. Please try again.\n";
    }
    cout << "\t\tPlease Press Any Key to Continue";
    getch();
}

// Profile Setting of Client
void profileSettingsClient(int& loggedInClientID, string userName[],
                           string password[], string clientName[],
                           string contactNumber[], int generalDBSize) {
    int choice;

    do {
        system("cls");  // Clear the screen
        cdmPrint();
        cout << "\n\n\t\t\tProfile Setting Menu\n";
        cout << "\t\t\t1. Change Username\n";
        cout << "\t\t\t2. Change Password\n";
        cout << "\t\t\t3. Update Name\n";
        cout << "\t\t\t4. Update Contact Number\n";
        cout << "\t\t\t0. Previous Menu\n";
        cout << "\n\t\t\tEnter your choice (0-4): ";
        choice = getValidMenuChoice(0, 4);

        switch (choice) {
            case 1: {
                string newUsername;
                bool isUnique = true;

                cout << "\n\t\tEnter your new username: ";
                cin >> newUsername;

                for (int i = 0; i < generalDBSize; i++) {
                    if (userName[i] == newUsername && i != loggedInClientID) {
                        isUnique = false;
                        break;
                    }
                }

                if (isUnique) {
                    userName[loggedInClientID] = newUsername;
                    cout << "\n\t\tUsername updated successfully!\n";
                } else {
                    cout << "\n\t\tThis username is already taken. Please try "
                            "another one.\n";
                }

                break;
            }

            case 2: {
                string newPassword;
                cout << "\n\t\tEnter your new password: ";
                newPassword = passwordValidator();

                password[loggedInClientID] = newPassword;
                cout << "\n\t\tPassword updated successfully!\n";
                break;
            }

            case 3: {
                string newName;
                cout << "\n\t\tEnter your updated name: ";
                newName = validateNameInput();

                clientName[loggedInClientID] = newName;
                cout << "\n\t\tName updated successfully!\n";
                break;
            }

            case 4: {
                string newContactNumber;
                cout << "\n\t\tEnter your new contact number: ";
                newContactNumber = validateContactNumber();

                contactNumber[loggedInClientID] = newContactNumber;
                cout << "\n\t\tContact number updated successfully!\n";
                break;
            }

            case 0:
                cout << "\n\t\t\tMoving Back to Previous Menu";
                cout << "\n\t\t\tPress any key to continue...";
                getch();

            default: {
                cout << "\n\t\tInvalid choice! Please try again.\n";
                continue;
                break;
            }
        }

        cout << "\n\t\tPress any key to continue...";
        getch();

    } while (choice != 0);
}

// File Handling Functions Prototypes

// Data Saving

void clientDataSaving(int clientID[], string clientName[],
                      string clientContact[], string clientUserName[],
                      string clientPassword[], int generalDBSize) {
    ofstream fout;
    fout.open("clientData.txt");
    if (!fout) {
        cout << "\t\tFalid To Open File for Client Data Saving\n";
        cout << "\t\tPress Any Key to Continue...";
        getch();
        return;
    }
    for (int i = 0; i < generalDBSize; i++) {
        if (clientID[i] != -99) {
            fout << clientName[i] << "," << clientID[i] << ","
                 << clientContact[i] << "," << clientUserName[i] << ","
                 << clientPassword[i];
            if (i < generalDBSize - 1) fout << endl;
        }
    }
    fout.close();
    return;
}
void inventoryDataSaving(int invID[], string invName[], int invModelYear[],
                         int invPopRating[], string invStatus[], int invPrice[],
                         int generalDBSize) {
    ofstream fout;
    fout.open("inventoryData.txt");
    if (!fout) {
        cout << "\t\tFalid To Open File for Inventory Data Saving\n";
        cout << "\t\tPress Any Key to Continue...";
        getch();
        return;
    }
    for (int i = 0; i < generalDBSize; i++) {
        if (invID[i] != -99) {
            fout << invName[i] << "," << invID[i] << "," << invModelYear[i]
                 << "," << invPopRating[i] << "," << invStatus[i] << ","
                 << invPrice[i];
            if (i < generalDBSize - 1) fout << endl;
        }
    }
    fout.close();
    return;
}

void orderDataSaving(int orderID[], int orderClientID[], int orderCarID[],
                     string orderStatus[], string orderDate[],
                     string appointmentDate[], string appointmentTime[],
                     string saleDates[], int generalDBSize) {
    ofstream fout;
    fout.open("orderData.txt");
    if (!fout) {
        cout << "\t\tFalid To Open File for Order Data Saving\n";
        cout << "\t\tPress Any Key to Continue...";
        getch();
        return;
    }
    for (int i = 0; i < generalDBSize; i++) {
        if (orderID[i] != -99) {
            fout << orderStatus[i] << "," << orderID[i] << ","
                 << orderClientID[i] << "," << orderCarID[i] << ","
                 << orderDate[i] << "," << saleDates[i] << ","
                 << appointmentDate[i] << "," << appointmentTime[i];
            if (i < generalDBSize - 1) fout << endl;
        }
    }
    fout.close();
    return;
}

void managerDataSaving(string managerSecurityQuestion,
                       string managerSecurityAnswer, string managerUserName,
                       string managerPassword) {
    ofstream fout;
    fout.open("managerData.txt");
    if (!fout) {
        cout << "\t\tFalid To Open File for Manager Data Saving\n";
        cout << "\t\tPress Any Key to Continue...";
        getch();
        return;
    }

    fout << managerSecurityAnswer << "," << managerSecurityQuestion << ","
         << managerPassword << "," << managerUserName;

    fout.close();
    return;
}

// Data Loading

void clientDataLoading(int clientID[], string clientName[],
                       string clientContact[], string clientUserName[],
                       string clientPassword[], int generalDBSize) {
    int i = 0;
    ifstream fin;
    fin.open("clientData.txt");
    if (!(fin)) {
        cout << "\t\tFailed to open file for Client Data Loading\n";
        cout << "\t\tPress any Key to Continue";
        getch();
        return;
    }
    while (!(fin.eof()) && i < generalDBSize) {
        char commaAbsorber;
        if (clientID[i] == -99) {
            getline(fin, clientName[i], ',');
            if (clientName[i].empty()) break;
            fin >> clientID[i] >> commaAbsorber;
            getline(fin, clientContact[i], ',');
            getline(fin, clientUserName[i], ',');
            getline(fin, clientPassword[i], '\n');
        }
        i++;
    }
    fin.close();
    return;
}
void inventoryDataLoading(int invID[], string invName[], int invModelYear[],
                          int invPopRating[], string invStatus[],
                          int invPrice[], int generalDBSize) {
    int i = 0;
    ifstream fin;
    fin.open("inventoryData.txt");
    if (!(fin)) {
        cout << "\t\tFailed to open file for Inventory Data Loading\n";
        cout << "\t\tPress any Key to Continue";
        getch();
        return;
    }
    while (!(fin.eof()) && i < generalDBSize) {
        if (invID[i] == -99) {
            char commaAbsorber;
            getline(fin, invName[i], ',');
            if (invName[i].empty()) break;
            fin >> invID[i] >> commaAbsorber;
            fin >> invModelYear[i] >> commaAbsorber;
            fin >> invPopRating[i] >> commaAbsorber;
            getline(fin, invStatus[i], ',');
            fin >> invPrice[i];
            fin.ignore();  // To Ignore New Line
        }
        i++;
    }
    fin.close();
    return;
}
void orderDataLoading(int orderID[], int orderClientID[], int orderCarID[],
                      string orderStatus[], string orderDate[],
                      string appointmentDate[], string appointmentTime[],
                      string saleDates[], int generalDBSize) {
    int i = 0;
    ifstream fin;
    fin.open("orderData.txt");
    if (!(fin)) {
        cout << "\t\tFailed to open file for Order Data Loading\n";
        cout << "\t\tPress any Key to Continue";
        getch();
        return;
    }
    while (!(fin.eof()) && i < generalDBSize) {
        char commaAbsorber;
        if (orderID[i] == -99)
            ;
        getline(fin, orderStatus[i], ',');
        if (orderStatus[i].empty()) break;
        fin >> orderID[i] >> commaAbsorber;
        fin >> orderClientID[i] >> commaAbsorber;
        fin >> orderCarID[i] >> commaAbsorber;
        getline(fin, orderDate[i], ',');
        getline(fin, saleDates[i], ',');
        getline(fin, appointmentDate[i], ',');
        getline(fin, appointmentTime[i], '\n');
        i++;
    }
    fin.close();
    return;
}
void managerDataLoading(string managerSecurityQuestion,
                        string managerSecurityAnswer, string managerUserName,
                        string managerPassword) {
    ifstream fin;
    fin.open("managerData.txt");
    if (!(fin)) {
        cout << "\t\tFailed to open file for Manager Data Loading\n";
        cout << "\t\tPress any Key to Continue";
        getch();
        return;

        getline(fin, managerSecurityAnswer, ',');
        getline(fin, managerSecurityQuestion, ',');
        getline(fin, managerPassword, ',');
        getline(fin, managerUserName, '\n');
    }
}

// Validations Of Inputs
int getValidMenuChoice(int minChoice, int maxChoice) {
    int choice;
    bool valid = false;

    while (!valid) {
        cin >> choice;

        if (cin.fail() || choice < minChoice || choice > maxChoice) {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\n\t\tInvalid input! Please enter a number between "
                 << minChoice << " and " << maxChoice << " : ";
        } else {
            valid = true;  // Valid input
        }
    }

    cin.ignore(1000000, '\n');
    return choice;
}

// Function to validate input for 'Y', 'y', 'N', or 'n'
char validateYesNoInput() {
    char input;
    while (true) {
        cout << "\n\t\tEnter your choice (Y/N): ";
        cin >> input;
        if (input == 'Y' || input == 'y' || input == 'N' || input == 'n') {
            return input;
        } else {
            cout << "\t\tInvalid input! Please enter 'Y' or 'N' only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Function to validate names
string validateNameInput() {
    string name = "";
    while (true) {
        getline(cin, name);

        if (name.length() < 4 && name.length() > 20) {
            cout << "\t\tInvalid name! Name should contain more than 4 letter "
                    "and\n\t\t not exceed 20 characters.\n";
            cout << "\t\tRe Enter Name : ";
            continue;
        }

        bool valid = true;
        for (int i = 0; i < name.length(); i++) {
            char c = name[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                  c == ' ')) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "\t\tInvalid name! Numbers and special characters are not "
                    "allowed.\n";
            cout << "\t\tRe Enter Name : ";
        } else if (name.empty()) {  // Prevent empty input
            cout << "\t\tInvalid name! Name cannot be empty.\n";
            cout << "\t\tRe Enter Name : ";
        } else {
            return name;
        }
    }
}

// Function to validate contact number
string validateContactNumber() {
    string contactNumber;
    while (true) {
        getline(cin, contactNumber);

        // Check length constraint
        if (contactNumber.length() != 11) {
            cout << "\t\tInvalid contact number! It must be exactly 11 digits "
                    "long.\n";
            cout << "\t\tRe Enter a Valid Number: ";
            continue;
        }

        if (contactNumber[0] != '0' || contactNumber[1] != '3') {
            cout << "\t\tInvalid contact number! It must start with '03'.\n";
            cout << "\t\tRe Enter a Valid Number: ";
            continue;
        }

        bool valid = true;
        // Here I have used range based loop
        for (char c : contactNumber) {
            if (c < '0' || c > '9') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout
                << "\t\tInvalid contact number! It must contain digits only.\n";
            cout << "\t\tRe Enter a Valid Number: ";
        } else {
            return contactNumber;
        }
    }
}

// Function For Validating Password
string passwordValidator() {
    string password;
    while (true) {
        getline(cin, password);

        if (password.length() < 8) {
            cout << "\t\tPassword is too short! It must be at least 8 "
                    "characters.\n";
            cout << "\t\tRe Enter Password : ";
        } else if (password.length() > 20) {
            cout << "\t\tPassword is too long! It must be less than or equal "
                    "to 20 characters.\n";
            cout << "\t\tRe Enter Password : ";
        } else {
            // Valid password
            return password;
        }
    }
}

// Year Validation
int validateModelYear() {
    int modelYear = 0;
    bool isValid = false;

    while (!isValid) {
        cin >> modelYear;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000000, '\n');
            cout << "\t\tInvalid input. Please enter a valid 4-digit year.\n";
            cout << "\t\tReEnter Year : ";
            continue;
        }

        if (modelYear >= 1970 && modelYear <= 2050) {
            isValid = true;
        } else {
            cout << "\t\tYear out of range. Please enter a year between 1970 "
                    "and 2050.\n";
            cout << "\t\tReEnter Year : ";
        }
    }

    return modelYear;
}
// Popularity Rating Validator
int validatePopularityRating() {
    int rating = 0;
    bool isValid = false;

    while (!isValid) {
        cin >> rating;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\t\tInvalid input. Please enter an integer between 0 and "
                    "9.\n";
            cout << "\t\tRe Enter Popularity : ";
            continue;
        }

        if (rating >= 0 && rating <= 9) {
            isValid = true;
        } else {
            cout << "\t\tInvalid rating. Please enter a rating between 0 and "
                    "9.\n";
            cout << "\t\tRe Enter Popularity : ";
        }
    }

    return rating;
}

// ID validation Function
int validateID(int generalDBSize) {
    int id = 0;
    bool isValid = false;

    while (!isValid) {
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\t\tInvalid input. Please enter a valid integer.\n";
            cout << "\t\tRe Enter ID : ";
            continue;
        }

        if (id >= 0 && id < generalDBSize) {
            isValid = true;
        } else {
            cout << "\t\tInvalid ID. The ID must be greater than 0 and less "
                    "than "
                 << generalDBSize << ".\n";
            cout << "\t\tRe Enter ID : ";
        }
    }

    return id;
}

// Function to validate price input
int validatePrice() {
    int price = 0;
    bool isValid = false;

    while (!isValid) {
        cin >> price;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000000, '\n');
            cout << "\t\tInvalid input. Please enter a valid integer.\n";
            cout << "\t\tRe Enter Price : ";
            continue;
        }

        if (price > 400000 && price < 100000000) {
            isValid = true;
        } else {
            cout << "\t\tInvalid price. The price must be greater than 400,000 "
                    "and "
                    "less than 100,000,000.\n";
            cout << "\t\tRe Enter Price : ";
        }
    }

    return price;
}

// Function to validate the date format YYYY-MM-DD
string validateDate() {
    string date;
    bool isValid = false;

    while (!isValid) {
        cin >> date;

        if (date.length() != 10) {
            cout << "\t\tInvalid format. The date should be in the format "
                    "YYYY-MM-DD.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
            continue;
        }
        if (date[4] != '-' || date[7] != '-') {
            cout << "\t\tInvalid format. The date should be in the format "
                    "YYYY-MM-DD.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
            continue;
        }

        string yearStr = "";
        string monthStr = "";
        string dayStr = "";

        for (int i = 0; i < 4; ++i) {
            yearStr += date[i];
        }

        for (int i = 5; i < 7; ++i) {
            monthStr += date[i];
        }

        for (int i = 8; i < 10; ++i) {
            dayStr += date[i];
        }

        bool isNumeric = true;
        for (int i = 0; i < 4; ++i) {
            if (yearStr[i] < '0' || yearStr[i] > '9') {
                isNumeric = false;
                break;
            }
        }

        for (int i = 0; i < 2; ++i) {
            if (monthStr[i] < '0' || monthStr[i] > '9') {
                isNumeric = false;
                break;
            }
        }

        for (int i = 0; i < 2; ++i) {
            if (dayStr[i] < '0' || dayStr[i] > '9') {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cout << "\t\tInvalid input. Please enter numeric values for the "
                    "date.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
            continue;
        }

        int year = 0, month = 0, day = 0;

        for (int i = 0; i < 4; ++i) {
            year = year * 10 + (yearStr[i] - '0');
        }
        for (int i = 0; i < 2; ++i) {
            month = month * 10 + (monthStr[i] - '0');
        }
        for (int i = 0; i < 2; ++i) {
            day = day * 10 + (dayStr[i] - '0');
        }

        if (year < 1900 || year > 2050) {
            cout << "\t\tInvalid year. Please enter a year between 1900 and "
                    "2050.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
            continue;
        }
        if (month < 1 || month > 12) {
            cout << "\t\tInvalid month. Please enter a month between 01 and "
                    "12.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
            continue;
        }

        bool validDay = false;

        // Check for valid days in each month
        if ((month == 1 || month == 3 || month == 5 || month == 7 ||
             month == 8 || month == 10 || month == 12) &&
            day <= 31) {
            validDay = true;
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                   day <= 30) {
            validDay = true;
        } else if (month == 2 && day <= 28) {
            validDay = true;
        }

        if (validDay) {
            isValid = true;
        } else {
            cout << "\t\tInvalid day for the given month. Please enter a valid "
                    "date.\n";
            cout << "\t\tRe Enter Date i(n this Format YYYY-MM-DD) :";
        }
    }

    return date;
}

// Function for Validation of Date
string validateTime() {
    string time;
    bool isValid = false;

    while (!isValid) {
        cin >> time;

        if (time.length() != 5) {
            cout << "\t\tInvalid time format. The time should be in the format "
                    "HH:MM.\n";
            cout << "\t\tRe Enter Time :";
            continue;
        }

        if (time[2] != ':') {
            cout << "\t\tInvalid time format. The time should be in the format "
                    "HH:MM.\n";
            cout << "\t\tRe Enter Time :";
            continue;
        }

        int hour = 0, minute = 0;

        for (int i = 0; i < 2; ++i) {
            if (time[i] < '0' || time[i] > '9') {
                cout << "Invalid input. Hours should be numeric.\n";
                cout << "\t\tRe Enter Time :";
                break;
            }
            hour = hour * 10 + (time[i] - '0');
        }

        for (int i = 3; i < 5; ++i) {
            if (time[i] < '0' || time[i] > '9') {
                cout << "Invalid input. Minutes should be numeric.\n";
                cout << "\t\tRe Enter Time :";
                break;
            }
            minute = minute * 10 + (time[i] - '0');
        }
        if (hour < 0 || hour > 23) {
            cout << "Invalid hour. Please enter a valid hour between 00 and "
                    "23.\n";
            cout << "\t\tRe Enter Time :";
            continue;
        }

        if (minute < 0 || minute > 59) {
            cout << "Invalid minute. Please enter a valid minute between 00 "
                    "and 59.\n";
            cout << "\t\tRe Enter Time :";
            continue;
        }
        isValid = true;
    }

    return time;
}