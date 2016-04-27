#include <iostream>
#include <vector>
using namespace std;
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
		Realm realm1, realm2;
		int num_incants;
		RealmPair(Realm r1, Realm r2){
			this->realm1 = r1;
			this->realm2 = r2;
			this->num_incants = editDistance(r1.charm, r2.charm, r1.charm.length(), r2.charm.length());
			cout << "Realm pair " << realm1.charm << "-" << realm2.charm << " edit distance: " << num_incants << "\n"; 
		};
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
class RealmsGraphNode{
	public:
		string charm;
		vector<RealmGraphNode*> linked_realms;
		vector<int> num_incants, cost;
		RealmGraphNode();
}
int main() {


	//------Input------
	int numOfRealms;
	cin >> numOfRealms;
	string arrayCharm[numOfRealms];
	int arrayNumOfMagi[numOfRealms];
	vector<int> magi_powers[numOfRealms];
	string start, end;



	for (int i = 0; i < numOfRealms; i++) {
		cin >> arrayCharm[i];
		cin >> arrayNumOfMagi[i];

		for (int j = 0; j < arrayNumOfMagi[i]; j++) {
			int x;
			cin >> x;
			magi_powers[i].push_back(x);
		}
	}
	cin >> start;
	cin >> end;

	//------/Input------
	cout << endl;
	vector<Realm> realms;
	for (int i = 0; i < numOfRealms; i++) {
		realms.push_back(*new Realm(arrayCharm[i], magi_powers[i]));
	}
	vector<RealmPair> pairs;
	for(int i = 0; i < realms.size() - 1; i++){
		for(int j = i + 1; j < realms.size(); j++){
			RealmPair p(realms[i], realms[j]);
			pairs.push_back(p);
		}
	}
	return 0;
}
