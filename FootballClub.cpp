#include "header.h"

class FootballClub {
	private:
		string idMembers;
		string contractTerm;
	public:
		bool checkday(string day){
			for(int i=0;i<day.length();i++){
				if(day[i]<48||day[i]>57){
					return false;
				}
				else 
					return true;
			}
		}
	bool checkmonth(string  month){
			for(int i=0;i<month.length();i++){
				if(month[i]<48||month[i]>57){
					return false;
				}
				else 
					return true;
			}
		}
	bool checkyear(string year){
	
			for(int i=0;i<year.length();i++){
				if(year[i]<48||year[i]>57){
					return false;
				}
				else 
					return true;
			}
		}	
	bool checkDate(string  day, string  month, string  year) {
		if(checkday(day)==false || checkmonth(month)==false ||checkyear(year)==false ){
		 return false;
		}
			
		int iday = stoi(day);
		int imonth = stoi(month);
		int iyear = stoi(year);
		switch (imonth) {
			case 1 :
			case 3:
			case 5 :
			case 7 :
			case 8 :
			case 10 :
			case 12 :
					if(iday<1 || iday > 31) {
						return false;
					}
					break;
			case 4 :
			case 6 :
			case 9 :
			case 11 :
				if(iday < 1 || iday > 30 ) {
					return false;
				}
				break;
			case 2 :
				if (iyear % 4 == 0) {
  					if (iyear % 100 == 0) {
   						 if (iyear % 400 == 0) {
							if(iday < 1 || iday > 29) {
								return false;
							}
					}else{
						if(iday < 1 || iday > 28) {
								return false;
					}}
				}else {
						if(iday < 1 || iday > 29) {
								return false;
							}
				}}else{
						if(iday < 1 || iday > 28) {
								return false;
				}}
					
				break;
			default :
				return false;
		}
		if(iyear <= 2022) {
			return false;
		} 
		return true;
		}
		void setMember(string idMembers){
			this->idMembers = idMembers;
		}
		string getMember(){
			return this->idMembers;
		}
		void setcontract(string contractTerm){
			this->contractTerm = contractTerm;
		}
		string getcontract(){
			return this->contractTerm;
		}
	FootballClub(){
		this->idMembers = " ";
		this->contractTerm = " ";
	}
	void input(){
		cout<<"Enter the ID.Members: ";
		string a = "CD";
		string b;
		do{
			cout<<"\n-------------------";
			cout<<"\nEnter last three number of ID:  ";
			for(int i=0 ;i<3;i++){
			cin>>b[i];
		}
		}while(b[0]<48 || b[0]>57 ||b[1]<48 || b[1]>57 ||b[2]<48 || b[2]>57);
		idMembers = a + b[0]+b[1]+b[2];
		cout<<"-------------------";
		cin.ignore();
		cout<<"\nEnter the Contract Term :\n";
		string  day,month,year;
		cout<<"-----------------------\n"; 
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		cout<<"-----------------------\n";
		contractTerm = day+'/'+month+'/'+year;
	}
	void output(){
		cout<<"*ID of Members: "<<this->idMembers<<endl;
		cout<<"*Contract Term: "<<this->contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual bool signingCondition() = 0;
	virtual void oppRenewContract() = 0;

};
