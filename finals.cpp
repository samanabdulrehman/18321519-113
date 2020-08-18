#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class appointement{
	
	private:
		
		string fname;
int 	age ;
string 	city ;
char	phone_number[13]  ;
int 	appointment_number; 
string	appointement_status;
int 	hours;
		
		int hoursbook;
		string name;

public:
	appointment()
{
	hoursbook = 8;
	fname=fname;
	
}
string agetter()
		{
			return fname;
		}
//
int bookAppointment()
{
    system("cls");
	
    cout<<"\n ----- Book Your Appointment ---- \n";	
    cout<<"\n ----- Availbale slots ---- \n";	 

    //check if record already exist..
    ifstream read;
    read.open(fname.c_str());
    
    
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n Appointment Summary by hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=12; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}
	
	else
	{								           	
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}
            
	}
		
	read.close();
    }
	if(recordFound == 0){
	cout<<"\n Appointment Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=21; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}
		
	}
   
   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<"\n Error : Invalid Selection";
	cout<<"\n Please selction correct value from menu A- Z";
	cout<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	bookAppointment();
   }
   
   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0) 
      isBooked = 0;
      
   if(isBooked ==1)
   {
   	cout<<"\n Error : Appointment is already booked for this Hour";
   	cout<<"\n Please select different time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	bookAppointment();
   }
   
  
   cout<<"\n Enter your first name:";
   cin>>name;  
   cout<<"Your Age\n";
   cin>>age;
   cout<<"Your City\n";
   cin>>city;
   ofstream out;
   out.open(fname.c_str(), ios::app);
	
   if(out){
	   out<<choice<<":"<<name.c_str()<<" "<<age<<" "<<city<<"\n";
	   out.close();
	   cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

int existingAppointment()
{
    system("cls");
    cout<<"\n ----- Appointments Summary ---- \n";	
    //check if record already exist..
    ifstream read;
    read.open(fname.c_str());
    
    int hoursbook = 8;
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	   while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;  
		   recordFound = 1;
	  }
        if(recordFound == 1)
        {
        cout<<"\n Appointment Summary by hours:";
        char key = 'A';
        int hours = 9;
        for(int i = 0; i<=12; i++)
        {
        	if(arr[i] == 0) 
        	cout<<"\n "<<key<<"->"<<hours<<" - Available";
        	else
        	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
        	hours++; key++;
        }
            
	}
		
	read.close();
    }
    else
    {
    char key = 'A';
	for(int i = 9; i<=21; i++)
	{
	if(i==9)
	cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
	else
	cout<<"\n "<<key<<" -> "<<i<<" - Available";
	key++;
	}
    }
    
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;	 
}

void  menu ()
{
	while(1)
	{
		system("cls");
		cout<<"\t\t\tPatient  Appointment System\n";
		cout<<"----------------------------------------\n\n";
		
		cout<<"1. Book Appointment\n";
		cout<<"2. Check Existing Appointment\n";
		cout<<"0. Exit\n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: bookAppointment(); break;
			case 2: existingAppointment(); break;
			case 0: 
		        while(1)
		        {
				 system("cls");
		        	cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        		exit(0);
		        	else if(ex == 'n' || ex == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;
                 	 
            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 	
		}   		        

	}
}


};

class dataclass:public  appointement
{
	string str[13];
	string fname;
	int size ;
	public:
		 string datagetter()
		{
			return *str;
			
		}
		void setter()
		{
			bookAppointment();
			
		}
		dataclass()
		{
			this->fname=agetter();
		
		size=0;
ifstream read;
    read.open(fname.c_str());
   while(!read.eof()){
			getline(read,str[size]);
			size++;
		}
	 
	 }
	 
	 int idgetter(string line)
	 {
	 	int recordFound;
	 	int index;
	 	ifstream read;
    read.open(fname.c_str());
	 	while(getline(read, line)) {
	   	   char temp = line[0];
	   	   index = (temp - 65);  
		   recordFound = 1;
		   break;
	  }
	  return index;
	 }
	 
	 void update()
	 {
	 	int op;
	 	cout<<"Enter Record number\n";
		 cin>>op;
		 cout<<"appoint ment Status\n";
		 cin>>str[op];
		 	 }
		 	 
		 	 void delet()
		 	 {
		 	 	int op;
		 	 cout<<"Enter Record number\n";
		 cin>>op;
		 cout<<"appoint ment Status\n";
		 str[op]="0";	
	
		 }
		 	 	
			  ~dataclass()
			  {
			  	ofstream out;
			  	 out.open(fname.c_str(), ios::app);
	
   for(int i=0;i<13;i++)
   {

	   out<<str[i]<<"\n";

			  }
		}
	
};

 

int main() {

appointement obj;
obj.menu();
	return 0;
} 
