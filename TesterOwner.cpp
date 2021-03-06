#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream> 
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
static int checkOwner = 0;
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
class Owner:public FootballClub{
	private:
		string corporTaxCode;//ma thue doanh nghiep
		long long netWorth;//gia tri rong
		long long netProfit;//loi nhuan rong
		string nameOfOwner;//ten chu so huu
		long long publicDebt;//no cong
		long long investmentAmount;//tien dau tu 
	public:
		void setTaxCode(string corporTaxCode){
			this->corporTaxCode=corporTaxCode;
		}
		string getTaxCode(){
			return this->corporTaxCode;
		}
		void setWorth(long long netWorth){
			 this->netWorth=netWorth;
		}
		long long getWorth(){
			return this->netWorth;
		}
		void setProfit(long long netProfit){
			 this->netProfit=netProfit;
		}
		long long getProfit(){
			return this->netProfit;
		}
		void setnameOwner(string nameOfOwner){
			this->nameOfOwner=nameOfOwner;
		}
		string getnameOwner(){
			return this->nameOfOwner;
		}
		void setDebt(long long publicDebt){
			this->publicDebt=publicDebt;
		}
		long long getDebt(){
			return this->publicDebt;
		}
		void setAmount(long long investmentAmount){
			this->investmentAmount=investmentAmount;
		}
		long long getAmount(){
			return this->investmentAmount;
		}
		
	Owner(){
		this->corporTaxCode=" ";
		this->netWorth=0;
		this->netProfit=0;
		this->nameOfOwner=" ";
		this->publicDebt=0;
		this->investmentAmount=0;
	}
	void input(){
		cout << endl << endl << "INPUT PROFILE : "<< endl << endl;
		FootballClub::input();
		cout<<"Enter the business tax code: ";
		cin>>this->corporTaxCode;
		cin.ignore();
		for(int i=0;i<=10;i++){
			if(this->corporTaxCode[i]>=97&&this->corporTaxCode[i]<=122)
				this->corporTaxCode[i]-=32;
		}
		cout<<"Total current net worth: ";
		cin>>this->netWorth;
		cout<<"Total current net profit: ";
		cin>>this->netProfit;
		cin.ignore();
		cout<<"Enter the Name of Owner: ";
		getline(cin,this->nameOfOwner);
		for(int i=0;i<=10;i++){
			if(this->nameOfOwner[i]>=97&&this->nameOfOwner[i]<=122)
				this->nameOfOwner[i]-=32;
		}
		cout<<"Enter the Public Debt: ";
		cin>>this->publicDebt;
		cout<<"The amount of money you intend to invest when They are elected: ";
		cin>>this->investmentAmount;
	}
	
	//
	
	void output(){
		cout << endl << endl << "PROFILE : " << endl << endl;
		FootballClub::output();
		cout<<"*Corpor TaxCode: "<<this->corporTaxCode<<endl;
		cout<<"*Net Worth: "<<this->netWorth<<"$"<<endl;
		cout<<"*Net Profit: "<<this->netProfit<<"$"<<endl;
		cout<<"*Name of Owner: "<<this->nameOfOwner<<endl;
		cout<<"*Public Debt: "<<this->publicDebt<<"$"<<endl;
		cout<<"*Investment Amount: "<<this->investmentAmount<<"$"<<endl;
	}
	
	// ROE da hoan thien
	
	double ROE(){
		double roe=this->netProfit/this->netWorth;
		return roe;
	}
	
	// bankruptcyRisk da hoan thien
	
	bool bankruptcyRisk(){
		if(this->publicDebt>=(this->netProfit+this->netWorth) && this->ROE()<0.02)
			return true;
		else 
			return false;
	}
	
	// mission da hoan thien
	
	string mission(){
		string mis = "Make club success!!";
		return mis;
	}
	
	// calculateWage chua hoan thien
	
	long long calculateWage(){
		double cal=this->netProfit-(this->investmentAmount+this->publicDebt);
		return cal;
	}
	
	//signingCondition da hoan thien
	
	bool signingCondition(){
		if (this->publicDebt<=((this->netProfit+this->netWorth)*2) && this->ROE()>0.15 && this->getAmount()!=0 && this->getAmount()>=1000000000)
			return true;
		else 
			return false;
	}
	
	//riskOfTerminateContract chua hoan thien
	
	void riskOfTerminateContract(){
		cout<<"*Risk Of Terminate Contract: ";
		//ROE & publicDebt & calWage
		if(this->signingCondition()==false){
			cout<<"\n-Contract Terminated!!\n";
		}else 
			cout<<"\n-The contract is still valid!!\n";
	}
	
	// oppRenewContract chua hoan thien
		
	void oppRenewContract(){
		cout<<"*OOP Renew Contract: ";
		if(this->signingCondition()==true){
			string renew;
			cin.ignore();
			cout<<"\nEnter the contract renewal period: ";
			getline(cin,renew);
			cout<<"-The contract renewal period: "<<renew<<endl;
		}else 
			cout<<"\nThe contract has been terminated!!!\n";
	}

};
class ListOwner{
//	private:

	public: 
		int n;
		vector<Owner> v;
		
	void inputList(){
		cin>>n;
		cout << "\n\nEnter the information of each candidate : \n\n";
		for(int i=0;i<n;i++){
			cout<<"\n\nCandidate "<<i+1<<" : ";
			Owner on;
			on.input();
			if(v.size()>=1) {
				while(on.getMember()==v[i-1].getMember() || on.getTaxCode()==v[i-1].getTaxCode()) {
					cout<<"\n\nEnter again!!";
					on.input();
				}
			}
			v.push_back(on);
		}
		ofstream fo("C:\\Users\\My PC\\Documents\\Group_project\\OC.txt");
		if(fo.is_open()){
			for(int i=0;i<v.size();i++){
				fo<<"-----------------Owner Candidate"<<i+1<<"---------------"<<endl;
				fo<<"*ID.Members: "<<v[i].getMember()<<endl;
				fo<<"*Contract Term: "<<v[i].getcontract()<<endl;
				fo<<"*Corpor TaxCode: "<<v[i].getTaxCode()<<endl;
				fo<<"*Name of Owner: "<<v[i].getnameOwner()<<endl;
				fo<<endl;
			}
			fo.close();
		}else 
			cout<<"File not found!!!!";
	}
	void outputList(){
		cout<<"----------------------------------------------------------------"<<endl<<endl<<endl;
		cout << "Detailed list of each candidate :\n\n";
		for(int i=0;i<v.size();i++){
			v[i].output();
		}
	}
	
	void chooseTheOwner() {
		for(int i=0 ; i<v.size() ; i++) {
			if(v[i].bankruptcyRisk()==true || v[i].signingCondition()==false || v[i].getAmount()<= 400000000) {
				v.erase(v.begin()+i);
				i--;
			}
		}
		
		if(v.size()!=0) {
			checkOwner++;
			for(int i=0 ; i<v.size() ; i++) {
			for(int j=i ; j<v.size() ; j++) {
				if(v[i].getAmount() < v[j].getAmount()) {
					Owner tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
			}
			while(v.size()!=1) {
			v.pop_back();
			}
		} else {
				cout << "\n\noop!!!There are no suitable candidates in all that you have entered !!!\n\nWe need to find other candidates\n\nEnter the number of candidates you have selected : ";
			}
		}
		void scriptOfOwner() {
			cout << "Our team currently has no owner !!! \n\nYou need to enter the number of potential candidates for the position of team owner : ";
			this->inputList();
			this->outputList();
			this->chooseTheOwner();
			while(checkOwner==0) {
				this->inputList();
				this->chooseTheOwner();
				
			}
			cout << "\n\nWe reviewed each person's details and the fan vote took place !!!\n\nWe would like to announce the official owner of the team is Mr."<<v[0].getnameOwner();
			ofstream fo("C:\\Users\\My PC\\Documents\\Group_project\\ON.txt");
			v[0].getMember()="ON01";
			
			if(fo.is_open()){
				fo<<"--------------------Official owner------------------ "<<endl;
				fo<<"*ID.Members: ON01"<<endl;
				fo<<"*Contract Term: "<<v[0].getcontract()<<endl;
				fo<<"*Corpor TaxCode: "<<v[0].getTaxCode()<<endl;
				fo<<"*Name of Owner: "<<v[0].getnameOwner()<<endl;
				fo<<"*Net Worth: "<<v[0].getWorth()<<"$"<<endl;
				fo<<"*Net Profit: "<<v[0].getProfit()<<"$"<<endl;
				fo<<"*Public Debt: "<<v[0].getDebt()<<"$"<<endl;
				fo<<"*Investment Amount: "<<v[0].getAmount()<<"$"<<endl;
				fo<<endl;
			
			fo.close();
		}else
			cout<<"File not found!!!!";
		}
};
int main() {
	ListOwner Lo;
	Lo.scriptOfOwner();
	return 0;
}

