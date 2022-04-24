#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<Stdlib.h>
#define size 7
using namespace std;

struct patient
{
    long long ID;
	string firstname;
	string lastname;
	int age;
	char blood[5];
	char gender;
	char A1[20];
	char A2[20];
    patient*next;
};
class linkedlist
{
patient *head,*last;
public:
linkedlist() 
{
head=NULL;
last=NULL;
}
    patient input();
    void DNAsearch(long long,char[8],char[8]);
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void getlastpatientout();
    void deletespecific(int);
    //void start();
    //void end();
    //void enqueue(patient *);
    //void init();
    //void exit_program();
    void listofpatients();
    void insert(patient*);
    int search(long long);
    void edit(long long);
    char departmentname[50];
};

int check(char a11[], char a12[], int c)
{ 
    int i, a=0, b=0,n=0;
    for(i=0;i<c;i++)
    { 
        if(a11[i]=='A')
        {
            if(a12[i]=='T')
                { a++; }
            else
            { b++; 
            break;
            }
        }
        else if(a11[i]=='T')
        {
            if(a12[i]=='A')
            {a++;}
            else
            { b++;
            break;
            }
        }
        else if(a11[i]=='G')
        {
            if(a12[i]=='C')
            {a++;} 
            else
            {
                b++;
                break; }
            
        }
        else if(a11[i]=='C')
        {
            if(a12[i]=='G')
            { a++; }
            else
            { b++;
                break;}
            
        }
        else
        {
            n++;
        }
        
    } 
    if(b==0 &&n==0)
    {
        return 1; }
    else
    {
        cout<<"\n The Inputed DNA is incorrect\n";
        return 0;
    }
}

void Input(patient *p){
	
	int flag=0;
    
   cout<<"\n   First name     : ";
   cin>>p->firstname; 
   
   cout << "   Last name      : ";
   cin>>p->lastname; 
   again:
   cout << "   Blood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;
 
    }
   cout<<"   Gender(m/f)    : ";
   cin>>p->gender;
   cout<<"   Age            : ";
   cin>>p->age;
   dna:
   cout<<"   DNA   STRAND 1  : ";
   cin>>p->A1;
   cout<<"   DNA   STRAND 2  : ";
   cin>>p->A2;
   
   if(check(p->A1,p->A2,8)==0){
   	cout<<"Invalid input";
   	goto dna;
   }
}

void output(patient *p)
{
cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
cout<<"\n   Patient data:\n";
cout<<"\n   First Name         : "<<p->firstname;
cout<<"\n   Last Name          : "<<p->lastname;
cout<<"\n   Gender             : "<<p->gender;
cout<<"\n   Age                : "<<p->age;
cout<<"\n   Blood Group        : "<<p->blood;
cout<<"\n   Mobile Number      : "<<p->ID;
cout<<"\n   DNA                : "<<p->A1<<"  "<<p->A2;
cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
}
 
void linkedlist :: edit(long long item){
	int t=0;
	patient*p=new patient();
	p=head;
	while(p->next!=NULL && p->ID !=item){
		p=p->next;
	}
	if(p->ID==item){
		output(p);
		cout<<"Re enter the patient details";
		Input(p);
		cout<<"Record has been edited";
		output(p);
		
	
	}
}

int linkedlist :: search(long long item)
{
	if(head==NULL){
		return false;
	}
	else{
		patient*p= new patient();
		p=head;
		while(p->next!=NULL && p->ID!=item){
			p=p->next;
		}
		if(p->ID==item){
			return true;
		}
		return false;
	}
}
void linkedlist :: DNAsearch(long long item, char a[8], char b[8])
{
	patient*p= new patient();
	p=head;
	while(p->next!=NULL && p->ID!=item){
		p=p->next;
	}
	if(p->ID==item){
		strcpy(a,p->A1);
		strcpy(b,p->A2);		
	}
}
void lps(char p[], int m, int l[])
{ 
    int length = 0;
    l[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (p[i] == p[length])
        { 
            length++;
            l[i] = length;
            i++;
        }
        else
        { 
            if (length!=0)
                length = l[length-1];
            else
            {
                l[i] = 0;
                i++;
            }
        }
    }
}

void kmpsearch(char p[], char t[], int m, int n)
{
    int c=0;
    int l[m];
    cout<<"\n\n RESULTS OF THE CHARACTERISTICS COMPARISON OF THE DNA SAMPLE";
    lps(p, m, l);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        { 
            j++;
            i++;
        }
        if(j==m)
        {
            c++;
            j = l[j-1];
        }
        else if (i < n && p[j] != t[i])
        { 
            if (j != 0)
                j = l[j-1];
            else
                i =i+1;
        }
        
    }
    if(c==0)
        cout<<"\n\n THE GIVEN CHARACTERISTIC COULD NOT BE FOUND"<<endl;
    else
    {
        double per=(c*m*100)/n;
        cout<<"\n THE DNA HAD "<<per<<"% CHARACTERISTICS"<<endl;
    }
}

void compare(char C11[], char D11[])
{
    int i, a=0,b=0,a1=8;
    float n;
    cout<<"\n RESULTS OF DNA SAMPLE COMPARISON :";
    for(i=0;i<a1;i++)
    {
        if(C11[i]==D11[i])
        {a++;}
        else
        {b++;}
    }
    float x=a,y=b;
    n=(x/((x+y))*100);
    cout<<"\nFrom the comparison of the two DNA samples, it is identified that the percentage of similarity between the two DNA's is :";
    cout<<n<<endl;
}
 
void linkedlist :: deletespecific(int item){
	if(head == NULL){
		cout<<"No records found\n";
	}
	else{
		patient*p =new patient();
		patient*p1=new patient();
		p=head;
		while(p->next!=NULL && p->ID != item){
			p= p->next;
		}
			if(p->ID == item){
				p1=p;
				p=p->next;
				p1->next=NULL;
				free(p);
				cout<<"\nDeleted\n";
			}
	}
	
}
 
int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}
 
patient linkedlist :: input()
{
    int flag=0;
   patient *p=new patient();
   cout << "\n   Please enter data for patient\n";
    
   cout<<"\n   First name     : ";
   cin>>p->firstname;
   
   
   cout << "   Last name      : ";
   cin>>p->lastname;
   
   
   
   again :
   cout << "   Blood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;
 
    }
   cout<<"   Gender(m/f)    : ";
   cin>>p->gender;
   cout<<"   Age            : ";
   cin>>p->age;
   get:
   cout<<"   Mobile number  : ";
   cin>>p->ID;
   if(search(p->ID)){
   	p->ID =0;
   	cout<<"\n Already exists \n";
   	goto get;
   }
   dna:
   cout<<"   DNA   STRAND 1  : ";
   cin>>p->A1;
   cout<<"   DNA   STRAND 2  : ";
   cin>>p->A2;
   
   if(check(p->A1,p->A2,8)==0){
   	goto dna;
   }
   return *p;
}
void linkedlist::insert(patient *p){
	if(head==NULL) 
     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
}


void linkedlist :: insertatbeg()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;
 
     if(head==NULL)
 
     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedlist:: insertatend()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;
 
     if(head==NULL)
     {
     head=p;
        last=p;
        p->next=NULL;
     }
     else
     {
     p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     cout <<"\n  ----------PATIENT ADDED-----------";
     output(p);
}
void linkedlist :: getpatientout()
{
     if(head==NULL)
     {
     cout<<"\n  No Patient to operate";
     }
     else
     {
     patient*p=new patient();
     p=head;
     head=head->next;
    cout << "\n  Patient to operate:";
        output(p);
}
}

void linkedlist :: getlastpatientout(){

	if(head == NULL){
		cout<< "\n No patient to operate";
	}
	else{
		patient*p = new patient();
		patient*p1 = new patient();
		p=head;
		while(p->next!=NULL ){
			p1=p;
			p=p->next;
		}
		if(p->next == NULL){
			p1->next=NULL;
			delete(p);
			cout<<"\nDeleted\n";
		}
	}
}
 
void linkedlist :: listofpatients()
{
     if(head==NULL)
     {
     cout<<"\n  No patient";
}
      system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     patient*p=new patient;
     p=head;
     while(p!=NULL)
     {
        cout<<"\n   Patient data:\n";
		cout<<"\n   First Name       : "<<p->firstname;
		cout<<"\n   Last Name        : "<<p->lastname;
		cout<<"\n   Gender           : "<<p->gender;
        cout<<"\n   Age              : "<<p->age;
        cout<<"\n   Blood Group      : "<<p->blood;
		cout<<"\n   Mobile Number    : "<<p->ID;
		cout<<"\n   DNA              : "<<p->A1<<"  "<<p->A2;
		cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p=p->next;
     }
     cout<<"\n";
}

int main(){
	
	int p;	
	linkedlist c;
	//in();
	//c.init();	
	back:
	p=0;	
	cout<<"\nChoose the corresponding option\n";
	cout<<"1.Add new patient record\n";
	cout<<"2.Display records of patients\n";
	cout<<"3.Search or edit record\n";
	cout<<"4.Delete the records\n";
	cout<<"5.Realtivity check\n";
	cout<<"6.Characteristic check\n";
	cout<<"7.Exit from the program\n";
	cin>>p;
	do{
		switch(p){
			case 1:
				c.insertatbeg();
				goto back;
				break;
			case 2:
				c.listofpatients();
				goto back;
				break;
			case 3:
				long long id;
				cout<<"Enter the id number: ";
				cin>>id;
				if(c.search(id)){
					c.edit(id);					
				}
				else{
					cout<<"Record not found";
				}
				goto back;				
				
			case 4:
				int d;
				cout<<"\nChoose the corresponding option\n";
				cout<<"1.Delete at the begining\n";
				cout<<"2.Delete at the ending\n";
				cout<<"3.Delete a specific record\n";
				cin>>d;
				switch(d){
					case 1:
						c.getpatientout();
						break;
					case 2:
						c.getlastpatientout();
						break;
					case 3:
						long long id;
						cout<<"Enter the id of the patient:";
						cin>>id;
						c.deletespecific(id);
						break;				
				}
				goto back;
				break;
			case 5:
				long long id1,id2;
				char p[2][8],q[2][8];
				char a1[8],b1[8],a2[8],b2[8];
				cout<<"Enter the id of patient 1: ";
				cin>>id1;
				cout<<"Enter the id of patient 2: ";
				cin>>id2;
				if(c.search(id1)&&c.search(id2)){
					c.DNAsearch(id1,a1,b1);					
					c.DNAsearch(id2,a2,b2);
					compare(a1,a2);						
				}				
				else{
					cout<<"Invalid id";
				}
				
				goto back;
			case 6:
				long long ID;
				char a[4],c1[8],d1[8];
				cout<<"Enter the id of patient: ";
				cin>>ID;
				cout<<"Enter the characterstic: ";
				cin>>a;
				if(c.search(ID)){
				c.DNAsearch(ID,c1,d1);
				kmpsearch(a,c1,4,8);
			    }
			    else{
			    	cout<<"Invalid id";
				}
				goto back;
				
				
			case 7 :
				
				system("cls");
				cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     			cout<<"\n  |-- THANK YOU--|";
     			cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
				//c.exit_program();
				exit(1);
		} 
	}
	while(p<8);
	return 0;
}
