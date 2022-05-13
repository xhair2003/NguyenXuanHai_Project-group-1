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
		string getTaxCode(){
			return this->corporTaxCode;
		}
		long long getWorth(){
			return this->netWorth;
		}
		long long getProfit(){
			return this->netProfit;
		}
		string getnameOwner(){
			return this->nameOfOwner;
		}
		long long getDebt(){
			return this->publicDebt;
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
		getline(cin,corporTaxCode);
		cout<<"Enter the Net Worth: ";
		cin>>netWorth;
		cout<<"Enter the Net Profit: ";
		cin>>netProfit;
		cin.ignore();
		cout<<"Enter the Name of Owner: ";
		getline(cin,nameOfOwner);
		cout<<"Enter the Public Debt: ";
		cin>>publicDebt;
		cout<<"Enter the Investment Amount: ";
		cin>>investmentAmount;
	}
	void output(){
		FootballClub::output();
		cout<<"--------------------------------------------------"<<endl;
		cout<<"===========OUTPUT THE PROFILE OF OWNER============"<<endl;
		cout<<"*Corpor TaxCode: "<<corporTaxCode<<endl;
		cout<<"*Net Worth: "<<netWorth<<endl;
		cout<<"*Net Profit: "<<netProfit<<endl;
		cout<<"*Name of Owner: "<<nameOfOwner<<endl;
		cout<<"*Public Debt: "<<publicDebt<<endl;
		cout<<"*Investment Amount: "<<investmentAmount<<endl;
	}
	double ROE(){
		double roe=netProfit/netWorth;
		return roe;
	} 
	bool bankruptcyRisk(){
		if(ROE<0.15)
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
	double calculateWage();
	bool signingCondition(){
		if (bankruptcyRisk==false)
			return true;
		else 
			return false;
	}
	void riskOfTerminateContract();
	void oppRenewContract();
	void valueBringingLastSeason();
};
