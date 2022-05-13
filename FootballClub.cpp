
class FootballClub{
	private:
		string idMembers;
		string contractTerm;
	public:
		string getMember(){
			return this->idMembers;
		}
		string getcontract(){
			return this->contractTerm;
		}
	FootballClub(){
		this->idMembers = " ";
		this->contractTerm = " ";
	}
	void input(){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"==============INPUT THE FOOTBALL CLUB============="<<endl;
		cout<<"Enter the ID.Members: ";
		getline(cin,idMembers);
		cout<<"Enter the ContractTerm: ";
		getline(cin,contractTerm);
	}
	void output(){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"=============OUTPUT THE FOOTBALL CLUB============="<<endl;
		cout<<"*ID of Members: "<<idMembers<<endl;
		cout<<"*Contract Term: "<<contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual double calculateWage() = 0;
	virtual bool signingCondition() = 0;
	virtual void riskOfTerminateContract() = 0;
	virtual void oppRenewContract() = 0;
	virtual void valueBringingLastSeason() = 0;
	
};

