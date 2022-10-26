#include<bits/stdc++.h>
#include<unistd.h>
#include "person.h"
using namespace std;

class patient:public person
{
    public:
    string id,blood_group,age,gender;
};
int number_of_patient=0;
patient pat[100];
char x;
void read_patient()
{
     ifstream in("patient.txt");
     int i=0;
     string s;
     while(getline(in,pat[i].id))
     {
        getline(in,pat[i].name);
        getline(in,pat[i].age);
        getline(in,pat[i].gender);
        getline(in,pat[i].mobile_no);
        getline(in,pat[i].blood_group);
        i++;
        getline(in,s);
     }
     number_of_patient=i;
}
int is_valid_gender(string s)
{
    for(int i=0;i<s.length();i++)
    {
        s[i]=toupper(s[i]);
    }
    if(s=="MALE" || s=="FEMALE")
    {
        return 1;
    }
    cout<<"\n\tInvalid Gender Try Again..\n\n";
    cout<<"Gender : ";
    return 0;
}
int is_valid_Blood_Group(string bld_grp)
{
    for(int i=0;i<bld_grp.length();i++)
    {
        bld_grp[i] = toupper(bld_grp[i]);
    }
    int f=1;
    if(!(bld_grp=="A+"||bld_grp=="B+"||bld_grp=="O+"||bld_grp=="AB+"||
        bld_grp=="A-"||bld_grp=="B-"||bld_grp=="AB-"||bld_grp=="O-"))
    {
        cout<<"\n\tInvalid Blood Group Try Again..\n\n";
        cout<<"Blood Group : ";
        f=0;
        return f;
    }
    return f;
}
void search_patient()
{
     read_patient();
     cin.ignore();
     string idd;
     cout<<"Please give me the patient's ID : ";
     cin>>idd;
     for(int i=0;i<number_of_patient;i++)
     {
         if(pat[i].id==idd)
         {
            cout<<"ID          : "<<pat[i].id<<endl;
            cout<<"Name        : "<<pat[i].name<<endl;
            cout<<"Age         : "<<pat[i].age<<endl;
            cout<<"Gender      : "<<pat[i].gender<<endl;
            cout<<"Mobile NO.  : "<<pat[i].mobile_no<<endl;
            cout<<"Blood Group : "<<pat[i].blood_group<<endl;
            break;
         }
     }
     cout<<"Press any key to proceed...";
     cin>>x;
}
void update_info()
{
    read_patient();
    int option;
    string idd;
    cout<<"Which info do you want to update?\n\n";
    cout<<"1: Mobile Number?\n";
    cout<<"2: Age?\n";
    cin>>option;
    system("CLS");
    if(option!=1 && option != 2)
    {
        cout<<endl<<"Invalid Option, Please try Again..\n\n";
        update_info();
    }
    cout<<endl<<"Please give me the patient's ID you want to change : ";
    cin>>idd;
    int f=0;

    for(int i=0;i<number_of_patient;i++)
    {
        if(pat[i].id==idd)
        {

            if(option==1)
            {
                string m;
                cout<<"Enter the Mobile Number : ";
                cin>>m;
                pat[i].mobile_no=m;
                cout<<endl<<"Mobile Number has been updated successfully\n\n";
            }
            else if(option==2)
            {
                string m;
                cout<<"Enter the Age : ";
                cin>>m;
                pat[i].age=m;
                cout<<endl<<"Age has been updated successfully\n\n";
            }
            f=1;
        }
    }
    if(f==0)
    {
        system("CLS");
        cout<<endl<<":( Sorry couldn't find that ID, Please try Again..\n\n";
        update_info();
    }
    ofstream on("patient.txt");
    int i=0;
    while(i<number_of_patient)
    {
        on<<pat[i].id<<endl;
        on<<pat[i].name<<endl;
        on<<pat[i].age<<endl;
        on<<pat[i].gender<<endl;
        on<<pat[i].mobile_no<<endl;
        on<<pat[i].blood_group<<endl;
        i++;
        on<<"\n";
    }

    on.close();
     cout<<"Press any key to proceed...";
     cin>>x;
}
int r=0;
void remove_patient()
{
    read_patient();
    string o,del_id;
    getline(cin,o);
    int i=0,f=0;
    system("CLS");
    while(1)
    {
        cout<<"\nDELTETING PATIENT DETAILS\n";
        cout<<"-----------------------\n";
        cout<<"ID          : ";
        getline(cin,del_id);
        i=0,f=0;
        while(i<number_of_patient)
        {
            if(del_id==pat[i].id)
            {
                f=1;
            }
            i++;
        }
        if(f==0)
        {
            system("CLS");
            cout<<"\n\tInvalid ID, Please try again\n\n";
            sleep(2);
            system("CLS");
        }
        else break;
    }
    f=0;
    i=0;
    ofstream inn("patient.txt");
    while(i<number_of_patient)
    {
        if(del_id!=pat[i].id)
        {
            inn<<pat[i].id<<endl;
            inn<<pat[i].name<<endl;
            inn<<pat[i].age<<endl;
            inn<<pat[i].gender<<endl;
            inn<<pat[i].mobile_no<<endl;
            inn<<pat[i].blood_group<<endl;
            inn<<"\n";
        }
        else if(del_id==pat[i].id)
        {
            f=1;
        }
        i++;
    }
    system("CLS");
    cout<<"\n\tYour given information's are removed. Thanks for your co-operation.\n\n";
    number_of_patient--;
    cout<<"\n\tPress any key to proceed...";
    cin>>x;
    inn.close();

}
void patient_list()
{
    read_patient();
    int i = 0;
    cout<<"Patient List : \n";
    cout<<"-------------\n";
    while(i<number_of_patient)
    {
        cout<<"ID          : "<<pat[i].id<<endl;
        cout<<"Name        : "<<pat[i].name<<endl;
        cout<<"Age         : "<<pat[i].age<<endl;
        cout<<"Gender      : "<<pat[i].gender<<endl;
        cout<<"Mobile NO.  : "<<pat[i].mobile_no<<endl;
        cout<<"Blood Group : "<<pat[i].blood_group<<endl;
        i++;
        cout<<"\n"<<endl;
    }
     cout<<"Press any character to proceed...";
    cin>>x;
}
void add_patient()
{
    read_patient();
    patient new_patient;
    cout<<"\n\nADDING NEW PATIENT DETAILS\n";
    cout<<"------------------------\n";
    cin.ignore();
    cout<<"ID           : ";
    getline(cin,new_patient.id);
    cout<<endl;
    cout<<"Patient Name : ";
    getline(cin,new_patient.name);
    cout<<endl;
    cout<<"Age          : ";
    getline(cin,new_patient.age);
    cout<<endl;
    cout<<"Gender       : ";
    while(getline(cin,new_patient.gender))
    {
        if(is_valid_gender(new_patient.gender))
        {
            new_patient.gender[0]=toupper(new_patient.gender[0]);
            for(int i=1;i<new_patient.gender.length();i++)
            {
                new_patient.gender[i] = tolower(new_patient.gender[i]);
            }
            break;
        }
    }
    cout<<endl;
    cout<<"Moblie No.   : ";
    getline(cin,new_patient.mobile_no);
    cout<<endl;
    cout<<"Blood Group  : ";
    while(getline(cin,new_patient.blood_group))
    {
        if(is_valid_Blood_Group(new_patient.blood_group))
        {
            for(int i=0;i<new_patient.blood_group.length();i++)
            {
                new_patient.blood_group[i] = toupper(new_patient.blood_group[i]);
            }
            break;
        }
    }
    cout<<endl;
    ofstream on("patient.txt");
    int i=0;
    pat[number_of_patient].id = new_patient.id;
    pat[number_of_patient].name = new_patient.name;
    pat[number_of_patient].age = new_patient.age;
    pat[number_of_patient].gender = new_patient.gender;
    pat[number_of_patient].mobile_no = new_patient.mobile_no;
    pat[number_of_patient].blood_group = new_patient.blood_group;
    number_of_patient++;
    while(i<number_of_patient)
    {
        on<<pat[i].id<<endl;
        on<<pat[i].name<<endl;
        on<<pat[i].age<<endl;
        on<<pat[i].gender<<endl;
        on<<pat[i].mobile_no<<endl;
        on<<pat[i].blood_group<<endl;
        i++;
        on<<"\n";
    }
    on.close();
    system("CLS");
    cout<<"\n\tYour given information's are added. Thanks for your co-operation.\n\n";
    system("CLS");
    cout<<"Press any key to proceed...";
    cin>>x;
}
int mm=0;
void welcome()
{
    if(mm==0){
        cout<<"\n\t\tWELCOME TO THE PATIENT'S CRUD WORLD\n\n";
        sleep(1);
    }
        system("CLS");
        cout<<"\n\tPlease select an option\n";
        cout<<"\n\t1: Add a new patient\n\n";
        cout<<"\n\t2: Remove a patient's Information\n\n";
        cout<<"\n\t3: Search an individual patient's Information\n\n";
        cout<<"\n\t4: Update an old Patient's Information\n\n";
        cout<<"\n\t5: Show all Patient's Information\n\n";
        cout<<"\n\tEnter 0 to escape\n\n";
        int option;
        cin>>option;
        system("CLS");
        if(option == 0)
        {
             cout<<"\n\t\t\t\tStay with us\n\n";
             sleep(2);
             return;
        }
        mm=1;
        if(option>5 || option<1)
        {
            cout<<endl<<"Invalid Option, Please try Again..\n\n";
            sleep(2);
            system("CLS");

            welcome();
        }
        if(option == 1)
        {
            add_patient();
        }
        else if(option == 2)
        {
            remove_patient();
        }
        else if(option == 3)
        {
            search_patient();
        }
        else if(option == 4)
        {
            update_info();
        }
        else
        {
            patient_list();
        }
}
int main()
{
    while(1)
      welcome();

    return 0;
}

