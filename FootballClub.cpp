class FootballClub{
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
		cout<<"--------------------------------------------------"<<endl;
		cout<<"==============ENTER THE PROLIFE FOOTBALL CLUB============="<<endl;
		cout<<"Enter the ID.Members: ";
		cin>>this->idMembers;
		cin.ignore();
		cout<<"Enter the ContractTerm: ";
		getline(cin,this->contractTerm);
	}
	void output(){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"=============OUTPUT THE PROLIFE FOOTBALL CLUB============="<<endl;
		cout<<"*ID of Members: "<<this->idMembers<<endl;
		cout<<"*Contract Term: "<<this->contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual double calculateWage() = 0;
	virtual bool signingCondition() = 0;
	virtual void riskOfTerminateContract() = 0;
	virtual void oppRenewContract() = 0;
	virtual void valueBringingLastSeason() = 0;
};

