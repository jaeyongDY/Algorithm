#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
// trim from left
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}
// trim from right
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}
// trim from left & right
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

void solved() {
    int t, r, c, convert = 0;
    int p[22][22];
    string message = "";
    string result = "";
    string answer;
    cin >> t;
    for(int i=0; i<t; i++){
        message = "";
        result = "";
        convert = 0;
        answer = "";
        cin >> r >> c >> message;
        
        int cnt = 0;
        for(int row = 0; row < r; row++){
            for(int col = 0; col < c; col++){
                p[row][col] = message[cnt++];
            }
        }
        int x = 0, y = -1, direction = 1, numx = c, numy = r;
        
        while(true){
            for(int a = 0; a < numx; a++){
                y += direction;
                result += p[x][y];
            }
            numx--;
            numy--;

            for(int b = 0; b < numy; b++){
                x+= direction;
                result += p[x][y];
            }
            if(numx == 0 || numy == 0) break;
            
            direction*=-1;
        }
        for(int i=0; i < result.length(); i++){
            convert += (result[i] - '0') * pow(2, (4 - i%5));
            if((i+1) % 5 == 0){
                if(convert ==  0) {
                    answer += " ";
                }
                else {
                    answer += (char)(convert + 64);
                    convert = 0;
                }
            }
        }
        cout << trim(answer) << endl;
    }
}

int main(){
    solved();
    return 0;
}
