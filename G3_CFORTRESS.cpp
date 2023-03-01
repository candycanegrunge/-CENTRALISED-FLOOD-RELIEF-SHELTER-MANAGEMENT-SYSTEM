#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

//interface
const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;

void clearScreen(int characterLength) {
	for (int i = 0; i < characterLength; i++) {
		cout << "\b";
	}
}

void changeColour(int colour) {
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

void showLoadingScreen() {
	int i;
	string closed = "- - -", open = "* * *";
	int colour[] = {RED, GREEN, BLUE};
	
	cout << closed;
	
	for (i = 0; i < 3; i++) {
		Sleep(500);
		
		clearScreen(5);
		changeColour(colour[i]);
		
		cout << open;
		
		Sleep(500);
		
		clearScreen(5);
		changeColour(WHITE);
		
		cout << closed;
	}
	clearScreen(5);
	changeColour(WHITE);
}

void showBlinkingLights() {
	changeColour(RED);
	cout << "\t\t\t\tWELCOME";
	Sleep(1000);
	
	changeColour(GREEN);
	cout << " TO";
	Sleep(1000);
	
	changeColour(BLUE);
	cout << " FLOOD";
	Sleep(1000);
	
	changeColour(RED);
	cout << " RELIEF";
	Sleep(1000);
	
	changeColour(GREEN);
	cout << " SHELTER";
	Sleep(1000);
	
	changeColour(BLUE);
	cout << " MANAGEMENT";
	Sleep(1000);
	
	changeColour(RED);
	cout << " SYSTEM";
	Sleep(1000);
	
	changeColour(WHITE);
}

void loadingBar()	// Function to creating loading bar
{
    system("color 0B");
  
    char a = 177, b = 219;
    
    printf("\n\t\t\t\t\t"
            "LOADING....\n\n");
    printf("\t\t\t\t\t");

    for (int i = 0; i < 26; i++)
        printf("%c", a);
  
    printf("\r");
    printf("\t\t\t\t\t");
  
    for (int i = 0; i < 26; i++) {
        printf("%c", b);
  
        Sleep(10);
    }
    cout << endl << endl <<"\t\t\t\t\t";
    system ("PAUSE");
    system ("CLS");
}
	void CentralAdminHome ();
	void CentralSupplies ();
	void CentralDisplay_Shelter(); // Displaying from shelters
	
	void ShelterAdminHome();
	void Shelter_VictimManagement();
	void Shelter_InventoryManagement();

	void RemoveSupplyStock();
	void AddSupplyStock();
	void store(int ans);
	void DisplayInventory();
	void Shelter_Request();
	void TransportHandling();
	
	void loadingBar();
	
	void display (struct Details*); // display a line of data.
	void displayFull (struct Details*); // display full lines of data.
	void stringModify (struct Details*); // function to keep every data in margin by adding some spaces in every string (make program neatier)
	
	struct Details *insert (struct Details*, struct Details*); // function to insert data into BST nodes.
	struct Details *bstNode (struct Details*); // function to create new BST node
	struct Details *search ( struct Details *root, string key); // function to search a data from the BST.
	void result (struct Details*); // function to print the result from the searching
	
	string key;
	vector<vector<string>>request; //for requesting Supplies
	vector<string>TransportList; //for transport victim to other shelter
		
	int instruction;
	int choice;
	int count=0;
	int searchby; // user have to choose to search data by:
	int absent; // to detect if the result is absent (1) or found (0)
	int currentrec=0;

								   
	struct Details  //VICTIM STRUCT DETAILS
   { 
	//declare 5 details to be stored in victim's profile
	string firstname;
	string lastname;
	string ID_no;
	string age;
	string gender;
	
	Details *next;
	Details *right;
	Details *left;
   }*head, *tail, *temp, *temp2, *root;

int main()
{
  	cout << "\n\n\n";
  	cout << "      ";
	
 	showLoadingScreen();
  	showBlinkingLights();
	
  	cout << "\n\n\n";
  
	loadingBar();	
  
	int CSchoice;  
  	
  	cout << "\t\t              CENTRALISED FLOOD RELIEF SHELTER MANAGEMENT SYSTEM               " << endl;
  	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
	cout << "\t\t                                MAIN MENU                                      " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
  
	cout << "\t\t                           [1] Central Admin                                  " << endl;
	cout << "\t\t                           [2] Shelter Admin                                  " << endl;
	cout << "\t\t                           [3] Exit program                                   " << endl << endl;
    
    cout << "\t\t                            Enter your choice: ";
  	cin >>CSchoice;
  
  	switch(CSchoice)
    {
     	case 1: CentralAdminHome ();
             	cout<<endl;
             	break;

     	case 2: ShelterAdminHome();
             	cout<<endl;
             	break;
        
        case 3: return 0;
        		break;

    default: ;
    }
   
 	system ("CLS");
  
  	cout<<endl;

    return 0;
}

void CentralAdminHome ()
{
    int CAchoice;
    
    system ("CLS");
    
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
	cout << "\t\t                                CENTRAL ADMIN                                  " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;

    cout << "\t\t                           [1] Supplies Monitoring                             " <<endl;
    cout << "\t\t                           [2] Shelter Monitoring                              "<<endl;
    cout << "\t\t                           [0] MAIN MENU                                       "<<endl<<endl;

    cout << "\t\t                              Enter your choice: ";
    cin>>CAchoice;
    
    system ("CLS");
    
    switch(CAchoice)
    {
     	case 0: main();
     		 	break;
     		 
     	case 1: CentralSupplies();
             	break;

     	case 2: CentralDisplay_Shelter();
             	break;

    	default:cout<<endl;
              	break;
    }
}

void CentralSupplies()
{
   char YN;
   unsigned int i, j, request_size;
   int request_no;

   cout<< "\t\t------------------------  SUPPLIES REQUEST HANDLING  --------------------------"<<endl<<endl;

   for (i = 0; i < request.size(); i++)
    {
        cout<<"\t\t                "<<i+1;
        for (j = 0; j < request[i].size(); j++)
        {
         cout <<setw(20)<<request[i][j];
        }
        cout << endl;
    }

    cout<<endl;

    cout<<"\t\t                          Enter request to handle: ";
    cin >>request_no;

    cout<<endl;
    cout<<"\t\t                           Complete the request?"<<endl
        <<"\t\t                           [Y/y] YES      [N/n] NO"<<endl;
    cout<<"\t\t                               Enter Choice: ";
    cin >>YN;

    request_size=request.size();

    if(YN== 'Y' || YN == 'y')
    {
     //DELETE ROW OF COMPLETED REQUEST
     request.erase(request.begin() + request_no-1);

		cout<<"\t\t                             CURRENT REQUEST LIST "<<endl;
		cout<<"\t\t               ----------------------------------------------- "<<endl;     
	 
	 	for (i = 0; i < request.size(); i++)
        {
         cout<<endl<<"\t\t               "<<i+1 ;
         for (j = 0; j < request[i].size(); j++)
          {
           cout <<setw(20)<<request[i][j];
          }
        cout << endl;
    	}
    
    }
    else if (YN == 'N' ||YN == 'n')
    {
	 cout << endl;
	 cout<<"\t\t                             REQUEST NOT COMPLETE "<<endl;
     cout<<"\t\t               ----------------------------------------------- "<<endl;  
     cout<<"\t\t                        Returning to CENTRAL ADMIN page... "<<endl;
	
	 CentralAdminHome ();
	 system("PAUSE");
	 system("CLS");
    }
    else
    {
     CentralAdminHome (); 	
	}
	 system("PAUSE");
	 CentralAdminHome ();
		
}

void CentralDisplay_Shelter()
{	int SMchoice, i;
	
	cout <<endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
	cout << "\t\t                                SHELTER MONITORING                             " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl<<endl;

	cout << "\t\t                           [1] DISPLAY CURRENT REGISTERED VICTIM          "<<endl;
    cout << "\t\t                           [2] DISPLAY TRANSPORTED VICTIM                 "<<endl;
    cout << "\t\t                           [3] DISPLAY SHELTER INVENTORIES                "<<endl;
    cout << "\t\t                           [0] CENTRAL ADMIN WINDOW                       "<<endl<<endl;

    cout << "\t\t                               Enter your choice: ";
    cin>>SMchoice;
    
    system ("CLS");
    
    switch(SMchoice)
    {
     case 0: CentralAdminHome ();
     		 break;
     		 
	 case 1: 
	 		 cout<< "\t\t----------------------  CURRENT REGISTERED VICTIM LIST  -----------------------"<<endl<<endl;
	
			 displayFull (head);	
	
			 cout << endl;
			 system ("PAUSE");			
			 system ("CLS");
			 displayFull (head);
			 
			 system("CLS");
			 CentralDisplay_Shelter();
     		 break;

     case 2: 
     		 cout<< "\t\t----------------------  CURRENT TRANSPORTED VICTIM LIST  -------------------------"<<endl<<endl;
				
			 cout<< "\t\t--------------------  LIST OF PEOPLE TO BE TRANSPORTED  -----------------------"<<endl<<endl;
				 for (i=0; i<TransportList.size() ; i++)
			    {
				   cout<<"\t\t                 PERSON "<<i+1<<":  ";
				   cout<<TransportList[i]<<"\t";
				   cout<<endl;
				}
				   system ("PAUSE");
				   system("CLS");
				   CentralDisplay_Shelter();
				
			 
             break;
	
	case 3: 
			DisplayInventory();
			system("CLS");
			CentralDisplay_Shelter();
			
			break;
	
    default:CentralAdminHome ();
	 		 cout<<endl;
             break;
    }
	
}


void ShelterAdminHome()
{
	int SAchoice;
	system ("CLS");
	
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
	cout << "\t\t                                SHELTER ADMIN                                  " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
		
    cout << "\t\t                           [1] Victim Management                               "<<endl;
    cout << "\t\t                           [2] Inventory Management                            "<<endl;
    cout << "\t\t                           [0] MAIN MENU                                       "<<endl<<endl;

    cout << "\t\t                              Enter your choice: ";
    cin>>SAchoice;
    
    system ("CLS");
    
    switch(SAchoice)
    {
     case 0: main();
     		 break;
     		 
	 case 1: Shelter_VictimManagement();
     		 break;

     case 2: Shelter_InventoryManagement();
             break;

     default:ShelterAdminHome();
	 		 cout<<endl;
             break;
    }
}

void Shelter_VictimManagement() // function to manage victim details [insert, search, delete]
{
	Details *victim1, *victim2, *victim3, *victim4, *victim5, *newNode, *found;
	
	//creating nodes.
	victim1 = new Details;
	victim2 = new Details;
	victim3 = new Details;
	victim4 = new Details;
	victim5 = new Details;
	found   = new Details;
	
	victim1->firstname="Mo               "; victim1->lastname="Salah            "; victim1-> ID_no="010305040057      "; victim1->age="21        "; victim1-> gender="Male           ";
	victim2->firstname="Adham            "; victim2->lastname="Black            "; victim2-> ID_no="021114055186      "; victim2->age="20        "; victim2-> gender="Male           ";
	victim3->firstname="Lionel           "; victim3->lastname="Messi            "; victim3-> ID_no="050422039801      "; victim3->age="17        "; victim3-> gender="Male           "; 
	victim4->firstname="Ngolo            "; victim4->lastname="Kante            "; victim4-> ID_no="890828045188      "; victim4->age="33        "; victim4-> gender="Female         "; 
	victim5->firstname="Cristiano        "; victim5->lastname="Ronaldo          "; victim5-> ID_no="660531054082      "; victim5->age="56        "; victim5-> gender="Female         ";
	
	head=victim1;
	tail=victim1;
	
	victim1->next=victim2;
	tail=tail->next;
	
	victim2->next=victim3;
	tail=tail->next;
	
	victim3->next=victim4;
	tail=tail->next;
	
	victim4->next=victim5;
	tail=tail->next;
	
	do
	{ 
		system ("CLS");
		
		cout << "\t\t_______________________________________________________________________________" << endl;
		cout << "\t\t                                                                               " << endl;
		cout << "\t\t                             VICTIM MANAGEMENT                                 " << endl;
		cout << "\t\t_______________________________________________________________________________" << endl;
		cout << "\t\t                                                                               " << endl;
		cout << "\t\t                             Would you like to?  " << endl<< endl ;
		cout << "\t\t                            [1] Insert New Data" << endl;
		cout << "\t\t                            [2] Delete Data"  << endl;
		cout << "\t\t                            [3] Search Data"  << endl;
		cout << "\t\t                            [4] Display Data" << endl;
		cout << "\t\t                            [5] Transport to another shelter" << endl;
		cout << "\t\t                            [0] Shelter Admin Window" << endl << endl;
		cout << "\t\t                             Enter your choice: ";
		cin >> instruction;
		cout << endl;
		
		if (instruction==1) // instruction to insert new data
		{
			system ("CLS");
			
			newNode = new Details;			
			
			cout << endl;
			cout << "Please enter information below (Please start every word with capital letter):" << endl << endl;
			cout << "Enter Firstname: ";
			cin  >> newNode->firstname;	
			cout << endl << "Enter last name: ";
			cin  >> newNode->lastname;
			cout << endl << "Enter ID no: ";
			cin  >> newNode->ID_no; 
			cout << endl << "Enter Gender (M/F): ";
			cin  >> newNode->gender;
			
			if (newNode->gender=="m"||newNode->gender=="M")
			newNode->gender="Male";
			
			else if (newNode->gender=="f" || newNode->gender=="F")
			newNode->gender="Female";
			
			cout << endl << "Enter Age: ";
			cin >> newNode->age; 
			
			temp=newNode;
			
			tail->next=newNode;
			tail=temp;
			
			cout << endl << endl << "NEW DATA HAS BEEN INSERTED! \a" << endl;
			stringModify (newNode);
			
			system ("CLS");
		}
		
		else if (instruction==2) // instruction to delete data
		{
			int number;
			
			system ("CLS");
			
			displayFull (head);
			
			cout << "----------------------------------------------------------------------------------------------------------------" << endl;
			cout << endl << "Select which number of data you want to delete: ";
			cin >> number;
			
			if (number==1) // perform delete from the front if the user wants to delete the first data.
			{
				temp=head;
				head=temp->next;
				
				delete temp;		
			}
			
			else
			{
				temp=head;
				for (int i=0; i<number-2; i++)
				{
					temp=temp->next; 
				}
			
				temp2=temp->next;
			
				if (temp2==tail) // perform delete from the back if the user wants to delete the last data.
				{
					tail=temp; 
				}
			
				else // perform delete from the middle if the user wants to delete the middle data.
				temp->next=temp2->next; 
			
				delete temp2;
			}
			cout << endl << "PREVIOUS DATA NUMBER " << number << " HAS BEEN DELETED! \a" << endl <<endl;
			
			system("PAUSE");
			system ("CLS");
			cout<<"UPDATED VICTIM LIST"<<endl<<endl;
			displayFull (head);
		
		}
		
		else if (instruction==3) // instruction to search data through BST tree.
		{
			system ("CLS");
			cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
			cout << "Search by: " << endl << endl; // user have to choose to search data by:
			cout << "1. Firstname " << endl;
			cout << "2. Lastname" << endl;
			cout << "3. ID number" << endl;
		
			cout << "Enter your choice: " ;
			cin >> searchby;
			
			temp=head;
			
			struct Details *root = NULL; // root declaration
			
			while (temp!=tail->next) 
			{
				root=insert (root, temp); // insert datas into tree
				temp=temp->next; 
			}
			
			key = "NULL";
			cout << "================================================================================================================" << endl;
			cout << "Enter a keyword: ";
			cin >> key;
			
			found = search (root, key); // found data will be inserted into "found" node.
			
			cout << absent; 
			
			system ("CLS");
			
			if (absent==0)
			result (found);
			
			system ("CLS");
			displayFull (head);
		}
		
		else if (instruction==4)
		{
			system ("CLS");
				
			displayFull (head);	
				
			do
			{
				
				cout << endl;
				system ("PAUSE");
					
				system ("CLS");
				//displayFull (head);
			}
				
				while(choice!=0);
		}
		
		else if (instruction==5)
		{
		  system ("CLS");
	  	  TransportHandling();
		  system ("CLS");	  		  	
		}
		
		else if (instruction==0)
		{
			ShelterAdminHome();
		}
		
		else 
		break;
		
	}while (instruction==1||instruction==2||instruction==3||instruction==4||instruction==5||instruction==0);
}

void TransportHandling()
{
  int choice;
  int i;
  char YN;
  
  do{
	    system("CLS");
		cout<< "\t\t----------------------  TRANSPORT TO ANOTHER SHELTER  -------------------------"<<endl<<endl;
	
		cout << "\t\t                            [1] Display List" << endl;
		cout << "\t\t                            [2] Remove from List"  << endl;
		cout << "\t\t                            [3] Add to List"  << endl;
		cout << "\t\t                            [0] Victim Management Window" << endl << endl;  
	  
	    cout<< "\t\t                               Enter your choice: ";
	    cin>>choice;
	    system ("CLS");   
	  
			if (choice==1)
			{
				system("CLS");
				
				cout<< "\t\t--------------------  LIST OF PEOPLE TO BE TRANSPORTED  -----------------------"<<endl<<endl;
				 for (i=0; i<TransportList.size() ; i++)
			    {
				   cout<<"\t\t                 PERSON "<<i+1<<":  ";
				   cout<<TransportList[i]<<"\t";
				   cout<<endl;
				}
				system ("PAUSE");
			}
				
			else if (choice==2)
			{
				system("CLS");	
				int tnum;
				
				for (i = 0; i < TransportList.size(); i++)
			    {
			        cout<<"         "<<i+1;
			        cout <<setw(20)<<TransportList[i];
			        cout << endl;
			    }
			
			    cout<<endl;
			
			    cout<<"\t\t                         Enter person number to transport: ";
			     cin>>tnum;
			
			    cout<<endl<<endl;
				cout<<"\t\t                             Transport the victim?"<<endl
			        <<"\t\t                            [Y/y] YES      [N/n] NO"<<endl;
			    cout<<"\t\t                                Enter Choice: ";
			     cin>>YN;
			
			    if(YN== 'Y' || YN == 'y')
			    {
			     //DELETE ROW OF COMPLETED REQUEST
			     TransportList.erase(TransportList.begin() + tnum-1);
			    
					cout<< endl<<endl;
					cout<<"\t\t                   CURRENT LIST OF VICTIMS TO BE TRANSPORTED"<<endl;
					cout<<"\t\t               ----------------------------------------------- "<<endl;     
				 
				 	for (i = 0; i < TransportList.size(); i++)
			        {
			         cout<<endl<<"\t\t                        "<<i+1 ;
			         cout <<"\t\t "<<setw(30)<<TransportList[i];
			         cout << endl;
			    	}
				}
				else
				{
				 cout<<endl;
				 system("PAUSE");
				 system("CLS");
				 TransportHandling();	
				}
			}
			
			else if (choice==3)
			{
				system("CLS");
				
				int numpeople;
				string name;
				
				cout<< "\t\t               -------- Enter Names to be Transported ------- "<<endl<<endl;
				
				cout<< "\t\t                     Enter number of people to transport: ";
				cin>> numpeople;
				
				cout<< "\t\t                DO NOT ADD SPACE. Use _ in place of a space. "<<endl<<endl;				
				
				for (i=0; i<numpeople ; i++)
				{
				    cout<< "\t\t                Person "<<i+1<<":  ";
				    cin >> name;
				    TransportList.push_back(name);
				}
			}
			
			else if (choice==0)
			{
			system("CLS");
			Shelter_VictimManagement();
				
			}
			
			else
			{
			 system("CLS");
			 TransportHandling();
			}
			
	}while (instruction==1||instruction==2||instruction==3||instruction==0);		
		
}

void Shelter_InventoryManagement()
{
  int INchoice;
  system("CLS");
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
	cout << "\t\t                            INVENTORY MANAGEMENT                               " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t                                                                               " << endl;
  	
	cout << "\t\t                              Would you like to?  " << endl<< endl ;
	cout << "\t\t                            [1] Display Supplies" << endl;
	cout << "\t\t                            [2] Remove from Supply Stock"  << endl;
	cout << "\t\t                            [3] Add Items to Supply Stock"  << endl;
	cout << "\t\t                            [4] Request for Supplies"  << endl;
	cout << "\t\t                            [0] Shelter Admin Window" << endl << endl;  
  
    cout<< "\t\t                               Enter your choice: ";
    cin>>INchoice;
    
    system ("CLS");
    
    switch(INchoice)
    {
     case 0: ShelterAdminHome();
     		 break;
     		 
     case 1: DisplayInventory();
     		 Shelter_InventoryManagement();
     		 break;

     case 2: RemoveSupplyStock();
             break;
	 
	 case 3: AddSupplyStock();
             break;
             
     case 4: Shelter_Request();
	 		 cout<<endl;
             break;
             
     default: Shelter_InventoryManagement();
     		  break;
    }
}

void Shelter_Request()
{
  	int i, j, no_req;
  	char goback;
  	
	string item, quantity;
	//vector<vector<string>> request; // a multi-dim vec is a vector inside a vector
	
	cout<<endl;
	cout << "\t\t                            REQUEST FOR SUPPLIES                               " << endl;
	cout << "\t\t_______________________________________________________________________________" << endl;
	cout<<  "\t\t                      Enter Number of Requests : ";
	cin>> no_req;
	cout<<endl;
	 
	for (i=0; i<no_req ; i++)
	{
	   vector<string>temp;  // a temporary vector is created inside the loop for multi-dim vec
	   for (j=0; j<1; j++)
	   {
	    	cout<< "\t\t                REQUEST "<<i+1<<endl;
		 	cout<< "\t\t                DO NOT ADD SPACE. Use _ in place of a space. "<<endl;
		 	cout<< "\t\t               ---------------------------------------------- "<<endl;
		 	cout<< "\t\t                Enter Item Name: ";
	     	cin >> item;
	     	temp.push_back(item);
		 	cout<< "\t\t                Enter Item Quantity: ";
	     	cin >> quantity;
	     	temp.push_back(quantity);
	     	cout<<endl;
	   }
	   	cout<<endl;
	   	request.push_back(temp);
	   	temp.clear(); // the temporary vector contents are being wiped in every loop
	}
	
	cout<<endl;
	
	cout<<"\t\t                              TOTAL REQUESTS MADE "<<endl;
	cout<<"\t\t               ----------------------------------------------- "<<endl;
		 
	  for (i=0; i<no_req ; i++)
    {
	   cout<<"\t\t                 REQUEST "<<i+1<<":  ";
	   for (j=0; j<2; j++)
	   {
	    cout<<request[i][j]<<"\t";
	   }
	   cout<<endl;
	}
	
		cout<<"\n\n\n\n\n";
		cout<<"\t\t               Enter X to return to INVENTORY MANAGEMENT "<<endl;
		cout<<"\t\t               Enter 0 to return to SHELTER ADMIN WINDOW "<<endl;
		cout<<"\t\t               >> ";
		cin>>goback;
		cout<<endl;
	
	switch(goback)
	{
	  case 'x':
	  case 'X': system ("CLS"); 
	  			Shelter_InventoryManagement();
	  			break;
	  			
	  case '0': system ("CLS"); 
	  			ShelterAdminHome();
	  			break;
	  
	  default: system ("CLS"); 
	  		   ShelterAdminHome();
	  		   break;
	  			
	}
}

void DisplayInventory()
{
	int ans, type;
	int slot1=50, slot2=100, slot3=50, slot4=50, slot5=50, slot6=50, slot7=50;

	ifstream file;
	file.open("Victim reservation.txt");
	
	if (file.fail()) 
	{
	cerr << "Error opening file!" << endl;
	exit(1);
	}
	
	while (file >> type) 
	{
		if (type == 1)
			slot1 -= 1;
		if (type == 2)
			slot2 -= 1;
		if (type == 3)
			slot3 -= 1;
		if (type == 4)
			slot4 -= 1;
		if (type == 5)
			slot5 -= 1;
		if (type == 6)
			slot6 -= 1;
		if (type == 7)
			slot7 -= 1;
	}
	
	file.close();
	
	system("cls");
	cout << "Display Reservation" << endl;
	cout << "\n Slot 1 - Blankets          " << 50  - slot1 << "/50"  << endl;
	cout << "\n Slot 2 - Food              " << 100 - slot2 << "/100" << endl;
	cout << "\n Slot 3 - Toiletreies       " << 50  - slot3 << "/50"  << endl;
	cout << "\n Slot 4 - Men CLothes       " << 50  - slot4 << "/50"  << endl;
	cout << "\n Slot 5 - Woman Clothes     " << 50  - slot5 << "/50"  << endl;
	cout << "\n Slot 6 - Children Clothes  " << 50  - slot6 << "/50"  << endl;
	cout << "\n Slot 7 - Medical Kits      " << 50  - slot7 << "/50"  << endl << endl << endl;

	system ("pause");
	system ("cls");
}

void AddSupplyStock()
{
	int ans, type;
	int slot1=50, slot2=100, slot3=50, slot4=50, slot5=50, slot6=50, slot7=50;

	ifstream file;
	file.open("Victim reservation.txt");
	
	if (file.fail()) 
	{
	cerr << "Error opening file!" << endl;
	exit(1);
	}
	
	while (file >> type) 
	{
		if (type == 1)
			slot1 -= 1;
		if (type == 2)
			slot2 -= 1;
		if (type == 3)
			slot3 -= 1;
		if (type == 4)
			slot4 -= 1;
		if (type == 5)
			slot5 -= 1;
		if (type == 6)
			slot6 -= 1;
		if (type == 7)
			slot7 -= 1;
	}
	
	file.close();

	cout << "\n Slot Reservation " << endl;
	cout << "\n Slot 1 - Blankets          " << 50 - slot1 << "/50" << endl;
	cout << "\n Slot 2 - Food              " << 100 - slot2 << "/100" << endl;
	cout << "\n Slot 3 - Toiletreies       " << 50 - slot3 << "/50" << endl;
	cout << "\n Slot 4 - Men CLothes       " << 50 - slot4 << "/50" << endl;
	cout << "\n Slot 5 - Woman Clothes     " << 50 - slot5 << "/50" << endl;
	cout << "\n Slot 6 - Children Clothes  " << 50 - slot6 << "/50" << endl;
	cout << "\n Slot 7 - Medical Kits      " << 50 - slot7 << "/50" << endl;
	cout << "\n Select your choice : ";
	cin >> ans;
	
	switch (ans)
	{
		case 1: 
		{
			if (slot1 == 0)
			{
				cout << "\n Error! Slot 1 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 1 - Blankets " << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			system("cls");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 2:
		{
			if (slot2 == 0)
			{
				cout << "\n Error! Slot 2 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 2 - Food" << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 3:
		{
			if (slot3 == 0)
			{
				cout << "\n Error! Slot 3 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 3 - Toiletreies" << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 4:
		{
			if (slot4 == 0)
			{
				cout << "\n Error! Slot 4 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 4 - Men CLothes" << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 5:
		{
			if (slot5 == 0)
			{
				cout << "\n Error! Slot 5 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 5 - Woman Clothes " << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 6:
		{
			if (slot6 == 0)
			{
				cout << "\n Error! Slot 6 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 6 - Children Clothes" << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
		
		case 7:
		{
			if (slot7 == 0)
			{
				cout << "\n Error! Slot 7 is FULL !!!"<<endl;
				system ("pause");
				system("cls");
				Shelter_InventoryManagement();
			}
			
			system("cls");
			char confirm;
			cout << "Slot 7 - Medical Kits" << endl;
			cout << "Confirm Decision (y|n) : ";
			cin >> confirm;
			
			if (confirm == 'Y' || confirm == 'y') 
			{
			store(ans);
			system("pause");
			Shelter_InventoryManagement();
			}
			
			else
				Shelter_InventoryManagement();
			break;
		}
	}
	cout << endl;
	system ("pause");
	system ("cls");
	Shelter_InventoryManagement();
}

void store(int ans)
{
	string slottype;
	system("cls");
	switch (ans)
	{
		case 1:
			{
				slottype = " Slot 1 - Blankets ";
				break;
			}
		case 2:
			{
				slottype = " Slot 2 - Food ";
				break;
			}
		case 3:
			{
				slottype = " Slot 3 - Toiletries ";
				break;
			}
		case 4:
			{
				slottype = " Slot 4 - Men Clothes";
				break;
			}
		case 5:
			{
				slottype = " Slot 5 - Woman Clothes ";
				break;
			}
		case 6:
			{
				slottype = " Slot 6 - Children Clothes ";
				break;
			}
		case 7:
			{
				slottype = " Slot 7 - Medical Kits ";
				break;
			}
	}

	int numvictim=0, i;
	cout << " Total Number of Victim : ";
	cin >> numvictim;

    //insert data inside file
    ofstream file1("Victim reservation.txt", ios::app);
    for( i = 0;i<numvictim;i++){
        file1 << ans << ' ' << endl;
    }
    file1.close();
    
	system ("cls");
	DisplayInventory();
}

void RemoveSupplyStock()
{
	system("cls");
	
	int slot, x, i=1, count=1;
	char r, answer; 
	ifstream file;
	file.open("Victim reservation.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\t\t\t                  Inventory Reservation\n";
			
	cout <<"\t\t\t Slot 1 - Blanket                            Slot 2 - Food"<<endl;
	cout <<"\t\t\t Slot 3 - Toileteries                        Slot 4 - Men Clothes"<<endl;
	cout <<"\t\t\t Slot 5 - Women Clothes                      Slot 6 - Children Clothes"<<endl;
	cout <<"\t\t\t Slot 7 - Medical Kits"<<endl<<endl;
	
	while (file >> slot)
	{
		cout << endl << "\t" << i << " . ";
		cout << "Slot " << slot;
		i++;
	}
	
	file.close();
	file.open("Victim reservation.txt");
	
		cout << "\n\nType 'r' to remove a line"<<endl<<endl; 
		cout << "Type '0' to go back"<<endl<<endl;
		cout<<">> ";
		cin >> r;
	
		if (r=='0')
	{
		cout << " go back " << endl;
		system("cls");
		Shelter_InventoryManagement();	
	}
	
	if (r=='r'){
		cout << "\nSelect line :";
		cin >> x;
		while (file >> slot)
		{
			if(x!=count)
				temp << slot <<' '<< endl;
			count++;
		}
	}

	file.close();
	temp.close();
	file.open("Victim reservation.txt",ios::out|ios::trunc);
	file.close();
	rename("Victim reservation.txt","z.txt");
	rename("temp.txt","Victim reservation.txt");
	rename("z.txt","temp.txt");
	
	system ("pause");
	system ("cls");
	Shelter_InventoryManagement();
}

void stringModify (struct Details *data) // function to keep every data in margin by adding some spaces in every string (make program neatier)
{
	while (data->firstname.size()!=17)
	data->firstname+=" ";
	
	while (data->lastname.size()!=17)
	data->lastname+=" ";
	
	while (data->ID_no.size()!=18)
	data->ID_no+=" ";
	
	while (data->gender.size()!=15)
	data->gender+=" ";
	
	while (data->age.size()!=10)
	data->age+=" ";
}
		
struct Details *insert (struct Details *node, struct Details *data) // function to insert data into BST nodes.
{
	if (node==NULL)
	return bstNode (data); // return a new node because the tree is empty, else data will be inserted into a proper place:
	
	if (searchby == 1) // search by firstname
	{
		if (data->firstname < node->firstname)
		node->left = insert (node->left, data);
			
		else 
		node->right = insert (node->right, data); 
	}
	
	if (searchby == 2) // search by lastname
	{
		if (data->lastname < node->lastname)
		node->left = insert (node->left, data);

		else 
		node->right = insert (node->right, data); 
	}
	
	if (searchby == 3) // search by ID number
	{
		if (data->ID_no < node->ID_no)
		node->left = insert (node->left, data);

		else 
		node->right = insert (node->right, data); 
	}
	
	return node;
		
}
	
struct Details* search(struct Details* root, string key) // function to search a data from the BST.
{ 
	absent=0;
	
	if (searchby==1)
	{
		
		while (key.size()!=17)
		key+=" ";
		
		while (root!=NULL)
		{
		
	    if (root-> firstname == key) // key is found
    	return root;
 
   	 	if (root->firstname < key) // key is at the right branch of the tree.
    	return search(root->right, key); 
  
    	return search(root->left, key); // key is at the left branch of the tree.
    	}
    	
    	system ("CLS");
    	cout << "Search: " << key << endl;
		cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
    	cout << "NOT FOUND! \a" << endl << endl;
    	system ("PAUSE");
    	absent=1;
    	//return search(root, key);
		return 0;
	}	
	
	else if (searchby==2)
	{
		
		while (key.size()!=17)
		key+=" ";
		
		while (root!=NULL)
		{
		
	    if (root-> lastname == key) // key is found
    	return root;
 
   	 	if (root->lastname < key) // key is at the right branch of the tree.
    	return search(root->right, key); 
   
    	return search(root->left, key); // key is at the left branch of the tree
    	}
    	
    	system ("CLS");
    	cout << "Search: " << key << endl;
		cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
    	cout << "NOT FOUND! \a" << endl << endl;
    	system ("PAUSE");
    	absent=1;

    	//return search(root, key);
    	return 0;
	}
	
	else if (searchby==3)
	{
		while (key.size()!=18)
		key+=" ";
		
		while (root!=NULL)
		{

	    if (root-> ID_no == key) // key is found
    	return root; 
     
   	 	if (root->ID_no < key) // key is at the right branch of the tree.
    	return search(root->right, key); 
  
    	return search(root->left, key); // key is at the left branch of the tree.
    	}
    	
    	system ("CLS");
    	cout << endl << "Search: " << key << endl;
		cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
    	cout << "DATA NOT FOUND! \a" << endl << endl;
    	system ("PAUSE");
    	absent=1;
    	return search(root, key);
	}
		return 0;
}
	
void result (struct Details *found) // function to print the result from the searching
{
	cout << "Search: \a" << key << endl;
	cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
	cout << "Search Result:" << endl << endl;
	cout << "Firstname    : " << found->firstname << endl;
    cout << "Last name    : " << found->lastname << endl;
    cout << "ID number    : " << found->ID_no << endl;
	cout << "Gender       : " << found->gender << endl;
	cout << "Age          : " << found->age << endl << endl;
	
	system ("PAUSE");
}

struct Details *bstNode (struct Details *data) // function to create new BST node.
{
	struct Details *temp2 =  new struct Details(); 
	temp2 = data;	
	temp2->left=temp2->right=NULL;
	return temp2;	
}
	
void display (struct Details *data) // function to display a line of data
{
	int i;
	i++;
	
	if (i<10) //to make number 10 and above allign with other rows.
	{
		cout << "\t\t" << i << ". " << data->firstname << data->lastname << data->ID_no << data->gender<< data->age; 
		cout << endl;
	}

	else 
	{
		cout << "\t\t" << i << "." << data->firstname << data->lastname << data->ID_no << data->gender<< data->age; 
		cout << endl;
	}
}
		
void displayFull (struct Details *data) // function to display full lines of data.
{
	cout << "\t\t___________________________________________________________________________" << endl;
	cout << "\t\t|                         Flood Victim's Information                      |" << endl;
	cout << "\t\t|_________________________________________________________________________|" << endl;
	cout << "\t\t|   Firstname   |   Last name   |      ID no.      |   Gender   |   Age   |" << endl;
	cout << "\t\t---------------------------------------------------------------------------" << endl;
		
	temp=head;
	display(head);
	while (temp!=tail)
	{
		temp=temp->next;
		display (temp);
	}
}