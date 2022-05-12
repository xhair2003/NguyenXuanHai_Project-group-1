
class FootballClub{
	public:
		string idMembers;
		string contractTerm;
	void input(){
		cout<<"Enter the ID.Members: ";
		getline(cin,idMembers);
		cout<<"Enter the ContractTerm: ";
		getline(cin,contractTerm);
	}
	void output(){
		cout<<"ID.Members: "<<idMembers<<"    ContractTerm: "<<contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual double calculateWage() = 0;
	virtual bool signingCondition() = 0;
	virtual void riskOfTerminateContract() = 0;
	virtual void oppRenewContract() = 0;
	virtual void valueBringingLastSeason() = 0;
};

