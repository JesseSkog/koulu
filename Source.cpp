#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <locale>


using namespace std;

void huoneet(int& huonemaara, vector<int>& huonehinnat) {
	huonemaara = 30 + rand() % 41;
	huonehinnat.resize(huonemaara);
	for (int& hinta : huonehinnat) {
		hinta = 80 + rand() % 21;
	}

}

int syotetarkistus(const string& syote, int min, int max) {
	int arvo;
	while (true) {
		cout << syote;
		cin >> arvo;

		if (cin.fail() || arvo < min || arvo >max){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virhe! Syötä kokonaisluku väliltä " << min << "-" << max << ".\n";
		}
		else {
			return arvo;
		}
	}
}

int main() {

	srand(time(nullptr));

	setlocale(LC_ALL, "fi-FI");

		int huonemaara;
		vector<int> huonehinnat;
		vector<bool> huonetila;

		huoneet(huonemaara, huonehinnat);
		huonetila.resize(huonemaara, false);
		cout << "Hotellissa on yhteensä " << huonemaara << " huonetta. \n";

		char varaa;
			do {
				cout << "Varaa huone\n";

				stringstream s;
				s << "Anna huonenumero (1-" << huonemaara << "):";
				string prompt = s.str();

				int huonenumero = syotetarkistus(prompt, 1, huonemaara);
				if (huonetila[huonenumero - 1]) {
					cout << "huone " << huonenumero << " on jo varattu. \n";
					continue;
				}
				int yot = syotetarkistus("Anna öiden määrä: ", 1, 30);

				int summa = huonehinnat[huonenumero - 1] * yot;
				cout << "huone " << huonenumero << " varattu " << yot << " yöksi. Loppusumma " << summa << " euroa. \n";

				huonetila[huonenumero - 1] = true;

				cout << "Haluatko varata vielä toisen huoneen? (k/e): ";
				cin >> varaa;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			} while (varaa == 'k' || varaa == 'K');
			cout << "Kiitos käytöstä! \n";
			return 0;
}