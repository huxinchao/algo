#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ox_map.h"

using namespace std;

char ORDER[4];

char HOST;
void set_order();

bool SET_ORDER_OK = false;
bool SET_HOST_OK = false;

void CAL_OX();
void initial_ox_map();

bool sortFun(pair<int,double>&, pair<int,double>&);

const double OX_P[11] = {
    0.336,
    0.066,
    0.065,
    0.066,
    0.065,
    0.068,
    0.065,
    0.066,
    0.065,
    0.066,
    0.074
};

const double OX_AVG = 3.7;



extern unordered_map<char,int> OX_MAP;

vector<vector<int>> USER_SCORE(27, vector<int>(11,0));
vector<int> USER_DEBT_COUNT(27,0);


int main() {
    initial_ox_map();

    ifstream if_user_score;
    ofstream of_user_score;

    if_user_score.open("user_score.txt");
    char user_score_buffer[256];
    
    if_user_score.getline(user_score_buffer, 256);
    while(if_user_score) {
        cout << "# READING ... ";
        cout << user_score_buffer << endl;
        for(int i = 0; i < 8; i += 2) {
            int user_n = user_score_buffer[i] - 97;
            int score_n;
            if(user_score_buffer[i+1] == 'n') {
                score_n = 0;
            } else {
                if(user_score_buffer[i+1] == '0') {
                    score_n = 10;
                } else {
                    score_n = user_score_buffer[i+1] - 48;
                }
            }
            USER_SCORE[user_n][score_n]++;
            USER_DEBT_COUNT[user_n]++;
        }
        if_user_score.getline(user_score_buffer, 256);
    }
    if_user_score.close();

    of_user_score.open("user_score.txt", ios_base::app);
    if(of_user_score.fail()) {
        cout << "OPEN ERROR !" << endl;
        
    }
    cout << "--- READING COMPLETE --- " << endl;

    string input;
    int input_flag = 1;
    while(1) {
        input_flag = 1;
        cout << "[Input] ";
        getline(cin, input);
        if(input[0] == 'o') {
            if(input.size() != 6) {
                cout << "[-]Set Order Error" << endl;
                continue;
            }
            for(int i = 2; i < 6; i++) {
                if(input[i] < 97 || input[i] > 123) {
                    cout << "[-]Set Order Error" << endl;
                    input_flag = 0;
                }
            }
            if(!input_flag) { continue; }
            for(int i = 2; i < 6; i++) {
                ORDER[i-2] = input[i];
            }
            cout << "[+]Set Order Success" << endl;
            SET_ORDER_OK = true;
        }

        if(input[0] == 'h') {
            if(input.size() != 3) {
                cout << "[-]Set Host Error" << endl;
                continue;
            }
            if(input[2] < 97 || input[2] > 123) {
                cout << "[-]Set Host Error" << endl;
                continue;
            }
            HOST = input[2];
            cout << "[+]Set Host Success" << endl;
            SET_HOST_OK = true;
            
        }

        if(input[0] == 's' && SET_ORDER_OK && SET_HOST_OK) {
            if(input.size() != 6) {
                cout << "[-]Set Score Error" << endl;
                input_flag = 0;
                continue;
            }
            for(int i = 2; i < 6; i++) {
                if((input[i] < 48 || input[i] > 57) && input[i] != 'n') {
                    cout << "[-]Set Score Error" << endl;
                    input_flag = 0;
                    break;
                }
            }

            if(!input_flag) {
                continue;
            }
            

            input = input.substr(2,4);
            cout << "[+] " << input << endl;
            string input_line;
            for(int i = 0; i < 4; i++) {
                input_line.push_back(ORDER[i]);
                input_line.push_back(input[i]);
                int user_n = ORDER[i] - 97;
                int score_n;
                if(input[i] == 'n') {
                    cout << "N" << endl;
                    score_n = 0;
                } else {
                if(input[i] == '0') {
                    score_n = 10;
                } else {
                    score_n = input[i] - 48;
                }
                
                }
                USER_SCORE[user_n][score_n]++;
                USER_DEBT_COUNT[user_n]++;
                


                
            
                
            }
            CAL_OX();
            of_user_score << input_line << endl;
        }

        if(input[0] == 'p') {
            cout << "<---- INFORMATION ---->" << endl;
            for(int i = 0; i < 4; i++) {
                cout << ORDER[i] << " ";
                for(int j = 0; j < 11; j++) {
                    cout << j << ":" << USER_SCORE[ORDER[i]-97][j] << " ";
                
                }
                cout << endl;
            }


            cout << endl;
            cout << "HOST: ";
            cout << HOST << endl;
            cout << "<--------------------->" << endl;
        }

        if(input[0] == 'k') {
            CAL_OX();
            break;
        }

        
    }

    of_user_score.close();


}

void CAL_OX() {


    double score_total[27] = {0};
    double out_list[27] = {0};
    int tmp_total = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 11; j++) {
            score_total[ORDER[i]-97] += USER_SCORE[ORDER[i]-97][j] * j;
        }
        double count_total = USER_DEBT_COUNT[ORDER[i]-97] * OX_AVG;

        double out = count_total - score_total[ORDER[i]-97];
        out /= count_total;

        out_list[ORDER[i]-97] = out;

    

        
    }

    cout << "<----- BET ----->" << endl;

    vector<pair<int,double>> vid;

    for(int i = 0; i < 4; i++) {
        if(ORDER[i] != HOST && out_list[ORDER[i]-97] > out_list[HOST-97]) {
            vid.push_back(make_pair(i, out_list[ORDER[i]-97] - out_list[HOST-97]));
            
        }
    }

    sort(vid.begin(), vid.end(), sortFun);

    for(int i = 0; i < vid.size(); i++) {
        cout << "# " << ORDER[vid[i].first] << " - " << vid[i].second << endl;
    }

    cout << "<----- BET ----->" << endl;

    

    



    

}

bool sortFun(pair<int,double>& a, pair<int,double>& b) {
    return a.second > b.second;
}











