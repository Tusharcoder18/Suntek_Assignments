#include<bits/stdc++.h>

using namespace std;

string solve(string text) {
    
    int space_count = 0, space_divide;
    string result, spaces;
    vector<string> words;
    
    // Split the text at " " and store in the vector words
    istringstream ss(text); 
    string word; 
    while (ss >> word)  
    { 
        words.push_back(word);
    } 
    
    int word_count = words.size();
    
    // Count the number of spaces(space count)
    for(int i=0; i<text.size(); i++) {
        if(text[i] == ' ') {
            space_count++;
        }
    }
    
    if(word_count == 1 && space_count == 0) {            // Example Input: "a"
        return text;
    } else if(word_count == 1 && space_count > 0) {      // Example Input: "  hello"
        result += words[0];
        for(int i=0; i<space_count; i++)
            result += " ";
    } else {                                             // All other test cases
        space_divide = space_count / (word_count-1);     // Number of even spaces
        // cout << space_divide << " ";
        for(int i=0; i<space_divide; i++)
            spaces += " ";

        // Append (n-1) words and even spaces
        for(int i=0; i<word_count-1; i++) {
            result += words[i];
            result += spaces;
        }
        result += words[word_count-1]; // Append the last word

        // Append extra spaces at the end in case of uneven count
        if(space_count % (word_count-1) != 0) {
            for(int i=0; i<(space_count % (word_count-1)); i++)
                result += " ";
        }
    }  
    // cout << result;
    
    return result;
}

int main() {
    string text;
    getline(cin, text);

    string result = solve(text);

    cout << result << endl;

    return 0;
}
