//  PayRoll v1.00
//  structure
//  Created by rUaSynth



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct employee
{
    //members
    int userID;
    string name;
    float payRate;
    int type;
};


int main()
    {
        employee emp[4];
        float tax,grossPay,netPay;
        double totalGross=0;
        double totalNet=0;
        float hours[4];
       
        
        
        for(int i=0;i<4;i++)//gets detail for each employee using a loop
        {
            cout<<"Enter details of employee "<<(i+1)<<endl;
            cout <<"UserID: ";
            cin>>emp[i].userID;
                while(emp[i].userID<1)
                    {
                        cout<<"ID must be greater than 0"<<endl;
                        cout<<"userID: ";
                        cin>>emp[i].userID;
                    }
            cout <<"Name: ";
            cin.ignore();//skips the return key for input
            getline (cin, emp[i].name);//used to get full input w/whitespaces
            
            cout <<"Pay Rate: ";
            cin>>emp[i].payRate;
                while(emp[i].payRate<1)//validation
                    {
                        cout<<"Pay rate must be greater than 0"<<endl;
                        cout<<"Pay Rate: ";
                        cin>>emp[i].payRate;
                    }
            
            cout <<"type (0 for union / 1 for managment): ";
            cin>>emp[i].type;
                while(emp[i].type != 1 && emp[i].type !=0)//validation
                    {
                        cout<<"error! enter a vaild employee type,(0 for union / 1 for managment) ";
                        cin>>emp[i].type;
                    }
            cout <<" " <<endl;
          
        }
        
        cout <<"Enter time card info"<<endl;//time card loop runs for each employee
        for (int i=0;i<4;i++)
        {
            cout<<"Hours worked for "<<emp[i].name<<":";
            cin>>hours[i];
            while (hours[i]<0)
            {
                cout<<"enter valid hours( 0 and up)"<<endl;
                cin>>hours[i];
            }
            
        }
    //setw use to space out report
        cout<<"Payroll Report"<<endl;
        cout<<left<<setw(5)<<"ID"<<setw(15)<<"Name"<<setw(8)<<"Gross Pay"<<" "<<setw(8)<<"Tax"<<setw(8)<<"Net Pay";
        cout<<endl;
        for (int i=0;i<4;i++)
        {
            if (hours[i]>40 && emp[i].type==0)
                grossPay = ((emp[i].payRate*40) + (emp[i].payRate * (hours[i]-40) * (1.5)));
            else
                grossPay = (hours[i] * emp[i].payRate);
            tax=grossPay*(.15);
            netPay=grossPay-tax;
            totalGross= totalGross+grossPay;
            totalNet+=netPay;
            cout << left << setw(5)<<emp[i].userID<<setw(16)<<emp[i].name<<setw(8)<<fixed<<setprecision(2)<<grossPay<<setw(8)<<tax<<setw(8)<<netPay<<endl;
        }
        cout<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"Total Gross Pay $"<<totalGross<<endl;
        cout<<"Total Net Pay $"<<totalNet<<endl;
        
        

return 0;
    }
