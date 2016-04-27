#include <iostream>
#include <vector>
using namespace std;

//realms each have a charm
//	people in realm can't move realms
//	change charm to change realm
//
//change charm by incantation
//	magi cast incantation
//	incantation can either add, remove, or change a single symbol
//	if magic uses incantation, only greater magi can change charm again
//	magi ask for number of gems equal to their power
class Realm {
	public:
		string charm;
		vector<int> magi_powers;
		Realm(){};
		Realm(string s, vector<int> i){
			this->charm = s;
			this->magi_powers = i;
		}
		
};
class RealmPair {
	public:
		Realm realm_1, realm_2;
		int num_incants;
		RealmPair(Realm r1, Realm r2){
			this->realm_1 = r1;
			this->realm_2 = r2;
			this->num_incants = editDistance(r1.charm, r2.charm, r1.charm.length(), r2.charm.length());
		};
		static vector<RealmPair> initPairs(vector<Realm> r){
			vector<RealmPair> pairs;
			for(int i = 0; i < r.size() - 1; i++){
				for(int j = i + 1; j < r.size(); j++){
					RealmPair p(r[i], r[j]);
					pairs.push_back(p);
				}
			}
		}
		int min(int x, int y, int z){
			return std::min(std::min(x,y), z);
		};
		int editDistance(string str1, string str2, int m, int n){
			int editTable[m+1][n+1];
			for (int i = 0; i <= m; i++) {
					for (int j = 0; j <= n; j++) {
							//If first string is empty, only option is to insert all chars of second string and vice versa
							if (i == 0) {
									editTable[i][j] = j;
							}
							else if (j == 0) {
									editTable[i][j] = i;
							}
							else if (str1[i-1] == str2[j-1]){
									editTable[i][j] = editTable[i-1][j-1];
							}
							else {
									editTable[i][j] = 1 + min(editTable[i][j-1], editTable[i-1][j], editTable[i-1][j-1]);
							}
					}
			}
			return editTable[m][n];
	};

};
int main() {


	//------Input------
	int numOfRealms;
	cin >> numOfRealms;
	string arrayCharm[numOfRealms];
	int arrayNumOfMagi[numOfRealms];
	vector<int> magi_powers[numOfRealms];




	for (int i = 0; i < numOfRealms; i++) {
		cin >> arrayCharm[i];
		cin >> arrayNumOfMagi[i];

		for (int j = 0; j < arrayNumOfMagi[i]; j++) {
			int x;
			cin >> x;
			magi_powers[i].push_back(x);
		}

		cout << "arrayMagiPower: ";


	}

	//------/Input------

	//check input
	cout << "arrayCharm: ";
	for (int i = 0; i < numOfRealms; i++) {
		cout << arrayCharm[i];
	}
	cout << endl;
	cout << "arrayNumOfMagi: ";
	for (int i = 0; i < numOfRealms; i++) {
		cout << arrayNumOfMagi[i];
	}
	cout << endl;
	cout << "arrayMagiPower: ";
	
	cout << endl;
	Realm realms[numOfRealms];
	for (int i = 0; i < numOfRealms; i++) {
		realms[i] = *new Realm(arrayCharm[i], magi_powers[i]);
	}
	
	return 0;
}
