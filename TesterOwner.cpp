#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
static int checkOwner = 0;
class FootballClub {
	private:
		string idMembers;
		string contractTerm;
	public:
		bool checkDate(int day, int month, int year) {
		switch (month) {
			case 1 :
			case 3:
			case 5 :
			case 7 :
			case 8 :
			case 10 :
			case 12 :
					if(day<1 || day > 31) {
						return false;
					}
					break;
			case 4 :
			case 6 :
			case 9 :
			case 11 :
				if(day < 1 || day > 30) {
					return false;
				}
				break;
			case 2 :
				if(day < 1 || day > 29) {
					return false;
				}
				break;
			default :
				return false;
		}
		if(year <= 2022) {
			return false;
		} 
		return true;
		}
		void setMember(string idMembers){
			this->idMembers = idMembers;
		}
		string getMember(string idMembers){
			return this->idMembers;
		}
		void setcontract(string contractTerm){
			this->contractTerm = contractTerm;
		}
		string getcontract(string contractTerm){
			return this->contractTerm;
		}
	FootballClub(){
		this->idMembers = " ";
		this->contractTerm = " ";
	}
	void input(){
		cout<<"Enter the ID.Members: ";
		cin>>this->idMembers;
		for(int i=0;i<=10;i++){
			if(this->idMembers[i]>=97&&this->idMembers[i]<=122)
				this->idMembers[i]-=32;
		}
		cin.ignore();
		cout<<"Enter the ContractTerm(Format DD/MM/YYYY): \n\n";
		int day,month,year;
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		string sday,smonth,syear;
		sday = to_string(day);
		smonth = to_string(month);
		syear = to_string(year);
		this->contractTerm = sday+'/'+smonth+'/'+syear;
	}
	void output(){
		cout<<"*ID of Members: "<<this->idMembers<<endl;
		cout<<"*Contract Term: "<<this->contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual long long calculateWage() = 0;
	virtual bool signingCondition() = 0;
	virtual void riskOfTerminateContract() = 0;
	virtual void oppRenewContract() = 0;
	virtual bool valueBringingLastSeason() = 0;
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
		cout<<"Enter the Corpor TaxCode: ";
		cin>>this->corporTaxCode;
		cin.ignore();
		for(int i=0;i<=10;i++){
			if(this->corporTaxCode[i]>=97&&this->corporTaxCode[i]<=122)
				this->corporTaxCode[i]-=32;
		}
		cout<<"Enter the Net Worth: ";
		cin>>this->netWorth;
		cout<<"Enter the Net Profit: ";
		cin>>this->netProfit;
		cin.ignore();
		cout<<"Enter the Name of Owner: ";
		getline(cin,this->nameOfOwner);
		cout<<"Enter the Public Debt: ";
		cin>>this->publicDebt;
		cout<<"Enter the Investment Amount: ";
		cin>>this->investmentAmount;
	}
	
	//
	
	void output(){
		cout << endl << endl << "PROFILE : " << endl << endl;
		FootballClub::output();
		cout<<"*Corpor TaxCode: "<<this->corporTaxCode<<endl;
		cout<<"*Net Worth: "<<this->netWorth<<endl;
		cout<<"*Net Profit: "<<this->netProfit<<endl;
		cout<<"*Name of Owner: "<<this->nameOfOwner<<endl;
		cout<<"*Public Debt: "<<this->publicDebt<<endl;
		cout<<"*Investment Amount: "<<this->investmentAmount<<endl;
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
		if (this->publicDebt<=((this->netProfit+this->netWorth)*2) && this->ROE()>0.15 && this->getAmount()!=0)
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
	
	// valueBringingLastSeason chua hoan thien
	
	bool valueBringingLastSeason(){
		return false;
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
			v.push_back(on);
		}
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
			if(v[i].bankruptcyRisk()==true || v[i].signingCondition()==false) {
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
		}
};
int main() {
	ListOwner Lo;
	Lo.scriptOfOwner();
	return 0;
}

