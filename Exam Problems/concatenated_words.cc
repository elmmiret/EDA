#include <iostream>
#include <vector>

using namespace std;

void write_words(const vector<string>& words, vector<bool>& usado, vector<int>& solution){
    if(solution.size() == words.size()){
        for(int idx : solution) cout << words[idx];
        cout << endl;
    }
    else{
        for(int i = 0; i < words.size(); ++i){
            if(not usado[i] and (solution.size() == 0 or words[solution.back()].back() != words[i][0])){
                usado[i] = true;
                solution.push_back(i);
                write_words(words,usado,solution);
                solution.pop_back();
                usado[i] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        words[i] = s;
    }

    vector<bool> usado(n, false);
    vector<int> solution;

    write_words(words, usado, solution);
}