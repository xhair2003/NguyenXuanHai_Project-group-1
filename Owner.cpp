#include "FootballClub.cpp"

class Owner:public FootballClub{
	private:
		string corporTaxCode;
		long long netWorth;
		long long netProfit;
		string nameOfOwner;
		long long publicDebt;
		long long investmentAmount;
	public:
		void setTaxCode(string corporTaxCode){
			this->corporTaxCode=corporTaxCode;
		}
		string getTaxCode(){
			return this->corporTaxCode;
		}
		void setWorth(long long netWorth){
			 this->netWorth=netWorth
		}
		long long getWorth(){
			return this->netWorth;
		}
		void setProfit(long long netProfit){
			 this->netProfith=netProfit
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
		cout<<"--------------------------------------------------"<<endl;
		cout<<"============INPUT THE PROFILE OF OWNER============"<<endl;
		cout<<"Enter the Corpor TaxCode: ";
		getline(cin,this->corporTaxCode);
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
		cout<<"--------------------------------------------------"<<endl;
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
		if(this->ROE()<0.15)
			return true;
		else 
			return false;
	}
	string mission(){
		string mis;
		cin.ignore();
		cout<<"Enter the quest content:";
		getline(cin,mis);
		return mis;
	}
	double calculateWage(){
		double cal=this->netProfit-(this->investmentAmount+this->publicDebt);
		return cal;
	};
	bool signingCondition(){
		if (this->bankruptcyRisk==false)
			return true;
		else 
			return false;
	}
	void riskOfTerminateContract();
	void oppRenewContract();
	void valueBringingLastSeason();
};
