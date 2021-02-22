#include<iostream>
#include<bits/stdc++.h>

using namespace std;


string solve(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    
    int N = S.size();
    int temp[N];
    // Fill the temp array with -1
    for(int i=0; i<N; i++)
        temp[i] = -1;
    
    // Traverse through each value from indexes
    for(int i=0; i<indexes.size(); i++) {
        int x = indexes[i];
        
        // Check if sources[i] is equal to S[x:sizeof(sources)]
        if(S.substr(x, sources[i].size()) == sources[i])
            temp[x] = i; // insert index value from indexes to temp (insert values from S later)
    }
    
    string result;
    int x = 0;
    while(x < N) {
        if(temp[x] >= 0) { // If temp not -1
            result += targets[temp[x]]; // Append targets value to result
            x += sources[temp[x]].size(); // Increment x
        } else { // If temp is -1
            result += S[x]; // Append the single char at S[x]
            x++; // Increment x
        }
    }
    
    return result;   
}

int main() {
    int t, temp;
    string S, temp1;
    vector<int> indexes;
    vector<string> sources;
    vector<string> targets;

    cin >> S;
    cout << "Enter number of indexes";
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> temp;
        indexes.push_back(temp);
    }
    for(int i=0; i<t; i++) {
        cin >> temp1;
        sources.push_back(temp1);
    }
    for(int i=0; i<t; i++) {
        cin >> temp1;
        targets.push_back(temp1);
    }

    string result = solve(S, indexes, sources, targets);
    cout << result;

    return 0;
}