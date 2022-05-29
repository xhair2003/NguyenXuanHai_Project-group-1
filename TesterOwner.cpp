#include<iostream>
#include<algorithm>
using namespace std;

class FootballClub {
	private:
		string idMembers;
		string contractTerm;
	public:
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
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"==============ENTER THE PROLIFE FOOTBALL CLUB============="<<endl;
		cout<<"Enter the ID.Members: ";
		cin>>this->idMembers;
		cin.ignore();
		cout<<"Enter the ContractTerm: ";
		getline(cin,this->contractTerm);
	}
	void output(){
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"=============OUTPUT THE PROLIFE FOOTBALL CLUB============="<<endl;
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
		FootballClub::input();
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"============INPUT THE PROFILE OF OWNER============"<<endl;
		cout<<"Enter the Corpor TaxCode: ";
		cin>>this->corporTaxCode;
		cin.ignore();
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
	void output(){
		FootballClub::output();
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"===========OUTPUT THE PROFILE OF OWNER============"<<endl;
		cout<<"*Corpor TaxCode: "<<this->corporTaxCode<<endl;
		cout<<"*Net Worth: "<<this->netWorth<<endl;
		cout<<"*Net Profit: "<<this->netProfit<<endl;
		cout<<"*Name of Owner: "<<this->nameOfOwner<<endl;
		cout<<"*Public Debt: "<<this->publicDebt<<endl;
		cout<<"*Investment Amount: "<<this->investmentAmount<<endl;
	}
	double ROE(){
		double roe=this->netProfit/this->netWorth;
		return roe;
	}
	bool bankruptcyRisk(){
		if(this->publicDebt>=(this->netProfit+this->netWorth)||this->ROE()<0.02)
			return true;
		else 
			return false;
	}
	string mission(){
		string mis = "Make club success!!";
		return mis;
	}
	long long calculateWage(){
		//chua hoan thien
		double cal=this->netProfit-(this->investmentAmount+this->publicDebt);
		return cal;
	}
	bool signingCondition(){
		//publicDebt & ROE 
		if (this->publicDebt<((this->netProfit+this->netWorth)/10) && this->ROE()>0.15)
			return true;
		else 
			return false;
	}
	void riskOfTerminateContract(){
		cout<<"*Risk Of Terminate Contract: ";
		//ROE & publicDebt & calWage
		if(this->signingCondition()==false){
			cout<<"\n-Contract Terminated!!\n";
		}else 
			cout<<"\n-The contract is still valid!!\n";
	}	
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
	bool valueBringingLastSeason(){
		return true;
	}
};
class ListOwner{
	public: 
		Owner on[100];
		int n;
	void Listin(){
		cout<<"Enter the number of candidate owners: ";
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"Owner "<<i<<" : "<<endl;
			on[i].input();
		}
	}
	void Listout(){
		cout<<"----------------------------------------------------------------"<<endl;
		for(int i=0;i<=n;i++){
			on[i].output();
			on[i].riskOfTerminateContract();
		}
	}
};
int main() {
	Owner on[100];
	ListOwner Lo;
	Lo.Listin();
	Lo.Listout();
	
	return 0;
}

