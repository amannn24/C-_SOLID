// ISP: Interface Segregation Principle
// No client should be forced to depend on methods it does not use.
// One fat interace need to be split to many smaller and relevant interfaces so that clients
// can know about the interfaces that are relevant to them

// 15-Jul-2018	Aman Kesarwani	Initial Creation

struct Document;

struct IMachine {
	// Avoid using this fat interface, why enforcing the client to implement all these methods if client needs only one of these.
	virtual void print(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
};

struct PrintingMachine : IMachine {
	// Printing machine needs only print implmentation not fax and scan, since it has to follow protocols of IMachine, 
	// fax and scan are doing nothing execpt the blank implementation.
	void print(Document& doc) override {};
	void fax(Document& doc) override {};
	void scan(Document& doc) override {};
};

// The solution would be to use slim interfaces. Break down the fat interfaces
struct IPrinter {
	virtual void print(Document& doc)=0;
};

struct IScanner {
	virtual void scan(Document& doc) = 0;
};

// Printer only needs the print implementation, so it can use IPrinter.
struct Printer : IPrinter {
	void print(Document& doc) override {};
};

// Scanner only needs the scan implementation, so it can use IScanner.
struct Scanner : IScanner {
	void scan(Document& doc) override {};
};

struct IAllRounderMachine: IPrinter, IScanner {

};

struct Machine : IMachine {
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner) : printer{ printer }, scanner{scanner} {
	}

	void print (Document& doc) override{
		printer.print(doc);
	}

	void scan(Document& doc) override;
};

int main()
{
    return 0;
}

