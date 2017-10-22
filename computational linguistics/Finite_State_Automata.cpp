/*
I'd like to thank my professor Dr. Dina Khattab for her time and good explaination
*/

/*
*****SFOTWARE REQ.******
*install graphviz
*install dot viewer
*/

/*
*****NOTE.******
*The software will create a file called tree.gv in the same class' direction
*just click on the file to open the visualization of the graph 
*/

/*
A Finite State Automaton (FSA) is a 5-tuple (Q, I, F, T, E) where:
Q = states 		a finite set;
I = initial states 	a nonempty subset of Q;
F = final states 	a subset of Q;
T = an alphabet;
E = edges 		a subset of Q x T -> Q.
*/
#include<bits/stdc++.h>
using namespace std;
const int MX = 1e3;
string states[MX],ini_states[MX],final_states[MX],input;
int num_of_states,num_of_ini_states,num_of_final_states,num_of_alph,num_of_edges;
vector<pair<int,char> > adj[MX];
vector<pair<pair<string,string>,char> > allE;
map<string,int> id;
char alphabet[30];
bool final[MX];
bool dfs(int ind , int node){
	if(ind == (int)input.size()) return 0;

	bool ret = 0;
	for(int i = 0 ; i < (int)adj[node].size() ; i++){
		if(adj[node][i].second == input[ind]){
			if(final[adj[node][i].first] && ind == (int)input.size()-1) return 1;
			ret |= dfs(ind+1,adj[node][i].first);
		}
	}
	return ret;
}

int main(){
	printf("Enter number of the states (Q): ");
	scanf("%d",&num_of_states);
	printf("Enter the set (Q): ");
	for(int i = 0 ; i < num_of_states ; i++) cin >> states[i],id[states[i]] = i;


	printf("# of the initial states (I): ");
	scanf("%d",&num_of_ini_states);
	printf("Enter the set (I): ");
	for(int i = 0 ; i < num_of_ini_states ; i++) cin >> ini_states[i];

	printf("# of the final states (F): ");
	scanf("%d",&num_of_final_states);
	printf("Enter the set (F): ");
	for(int i = 0 ; i < num_of_final_states ; i++){
		cin >> final_states[i];
		final[id[final_states[i]]] = 1;
	}

	printf("# of the alphabet (T): ");
	scanf("%d",&num_of_alph);
	printf("Enter the set (T): ");
	for(int i = 0 ; i < num_of_alph ; i++) cin >> alphabet[i];

	printf("# of edges (E): ");
	scanf("%d",&num_of_edges);
	printf("Enter the set (E): ");
	for(int i = 0 ; i < num_of_edges ; i++){
		string from,to; char val; cin >> from >> val >> to;
		adj[id[from]].push_back(make_pair(id[to],val));
		allE.push_back(make_pair(make_pair(from,to),val));
	}
	ofstream tree;
	tree.open("tree.gv");
	tree<<"digraph {\n";
	for(int i = 0 ; i <  num_of_edges ; i++){
		string toFile = allE[i].first.first;
		toFile += " -> ";
		toFile += allE[i].first.second;
		toFile += "[label=\"";
		toFile += allE[i].second;
		toFile += "\",weight=\"";
		toFile += allE[i].second;
		toFile += "\"];\n";
		tree << toFile;
	}
	tree<<"}";
	tree.close();
	while(true){
		printf("Word: ");
		cin >> input;
		if(input == "exit") break;
		else{
			bool check = 0;
			for(int i = 0 ; i < num_of_ini_states ; i++) check |= dfs(0,id[ini_states[i]]);
			if(check) cout << "ACCEPTED!\n";
			else cout << "WRONG WORD!\n";
		}
	}
}
/*
3
1 2 3
1 1
1 3
2 a b
5
1 a 2
1 b 3
2 b 3
3 a 2
3 b 3
 */
