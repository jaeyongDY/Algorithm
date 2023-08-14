#include<iostream>
#include<algorithm>

using namespace std;

void solved() {
    string document;
    string findword;
    int result = 0, cnt = 0;
    
    getline(cin, document);
    getline(cin, findword);
    
    while(true) {
        int i = 0;
        for(int j = cnt; j < document.length(); j++){
            if(i < findword.length()) {
                if(document[j] == findword[i]){
                    i++;
                }
                else{
                    cnt++;
                    break;
                }
            }
            
            if(i == findword.length()) {
                cnt += i;
                result++;
                break;
            }
        }
        if(cnt + findword.length() > document.length()){
            break;
        }
    }
    cout << result << endl;
}

int main(){
    solved();
    return 0;
}
