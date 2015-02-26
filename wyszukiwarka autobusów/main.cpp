#include <string>
#include <list>

using namespace std;

class IPolaczenie {
public:
	virtual string* pobierzSzczegoly(int& dlugoscTablicy) = 0;
	virtual void drukuj() = 0;
};

class Wyszukiwanie {
private:
	string przystanekPoczatkowy;
	string przystanekKoncowy;
	time_t data;
	int liczbaPrzesiadek;
public:
	Wyszukiwanie(string pP, string pK, time_t d, int lP) :
	  przystanekPoczatkowy(pP), przystanekKoncowy(pK), data(d), liczbaPrzesiadek(lP) {}
	list<IPolaczenie> szukajPolaczenia();
};

class Polaczenie;

class Wydruk {
public:
	static void drukujPolaczenie(Polaczenie p);
};

class Polaczenie : IPolaczenie {
private:
	time_t czasOdjazdu;
	time_t czasPrzyjazdu;
	string miejscePrzyjazdu;
	string miejsceOdjazdu;
public:
	Polaczenie(time_t cO, time_t cP, string mP, string mO) :
	  czasOdjazdu(cO), czasPrzyjazdu(cP), miejscePrzyjazdu(mP), miejsceOdjazdu(mO) {}
	string* pobierzSzczegoly(int& dlugoscTablicy);
	void drukuj() {
		Wydruk::drukujPolaczenie(*this);
	}
};

class PolaczenieBezposrednie : Polaczenie {
private:
	float dlugoscTrasy;
	float prowizorycznaCenaBiletu;
public:
	PolaczenieBezposrednie(time_t cO, time_t cP, string mP, string mO, float dT, float pCB) :
		Polaczenie(cO, cP, mP, mO), dlugoscTrasy(dT), prowizorycznaCenaBiletu(pCB) {}
	string* pobierzSzczegoly(int& dlugoscTablicy);
	void drukuj();
};

class MiejscePrzesiadki {
private:
	string miejscowosc;
	int peronPrzyjazdu;
	int peronOdjazdu;
public:
	MiejscePrzesiadki(string m, int pP, int pO) :
	  miejscowosc(m), peronPrzyjazdu(pP), peronOdjazdu(pO) {}
};

class PolaczeniePosrednie : Polaczenie {
private:
	MiejscePrzesiadki miejscePrzesiadki;
	time_t czasPrzesiadki;
public:
	PolaczeniePosrednie(time_t cO, time_t cP, string mP, string mO, MiejscePrzesiadki miejsce, time_t czasP) :
	  Polaczenie(cO, cP, mP, mO), czasPrzesiadki(czasP), miejscePrzesiadki(miejsce) {}
	string* pobierzSzczegoly(int& dlugoscTablicy);
	void drukuj();
};


int main() {
	return 0;
}