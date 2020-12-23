#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct MapNode {
    int v;
    MapNode* next;
    int w;
    MapNode(int x, int W = 0) : v(x), next(NULL), w(W) {}
};

struct NWNode {
    bool Known = false;
    int Dv = 63355;
    int Pv = 0;
};

void addLink(MapNode*, vector<vector<int>>);
void showTable(vector<NWNode>& vnw);
int findSmallestUnknownNode(vector<NWNode>&);

int main() {
    MapNode* mapTable[7];
    vector<NWNode> vNw(7);

    vNw[2].Dv = 0;



    

    for(int i = 0; i < 7; i++) {
        mapTable[i] = new MapNode(i+1);
    }

    cout << "# add link ..." << endl;

    addLink(mapTable[0], {{2,2},{4,1}});
    addLink(mapTable[1], {{4,3},{5,10}});
    addLink(mapTable[2], {{1,4},{6,5}});
    addLink(mapTable[3], {{3,2},{5,2},{6,8},{7,4}});
    addLink(mapTable[4], {{7,6}});
    
    addLink(mapTable[6], {{6,1}});

    cout << "# start UW route search" << endl;

    int curDist;
   

    for(curDist = 0; curDist < 7; curDist++) {
        for(int i = 0; i < 7; i++) {
            if(vNw[i].Known == false && vNw[i].Dv == curDist) {
                vNw[i].Known = true;
                MapNode* head = mapTable[i]->next;

                while(head) {
                    if(vNw[head->v-1].Dv == 63355) {
                        vNw[head->v-1].Dv = curDist + 1;
                        vNw[head->v-1].Pv = i + 1;
                      
                    }
                    head = head->next;
                }
            }
        }
    }

    showTable(vNw);

    cout << "-----" << endl;
    vector<NWNode> vv(7);

    vv[2].Dv = 0;

    

    queue<int> q;
    int v,w;

    q.push(2);

    while(!q.empty()) {
        v = q.front();
        q.pop();
        vv[v].Known = true;

        MapNode* head = mapTable[v]->next;

        while(head) {
            if(vv[head->v-1].Dv == 63355) {
                vv[head->v-1].Dv = vv[v].Dv + 1;
                vv[head->v-1].Pv = v + 1;
                q.push(head->v-1);
            }
            head = head->next;
        }
    }

    showTable(vv);

    vector<NWNode> vvv(7);

    vvv[2].Dv = 0;

    

    cout << "-- Dijkstra Algorithm --" << endl;

    while(1) {
        v = findSmallestUnknownNode(vvv);

        if(v == -1) { break; }

        vvv[v].Known = true;

        MapNode* head = mapTable[v]->next;

        while(head) {
            if(vvv[head->v-1].Known == false && vvv[v].Dv + head->w < vvv[head->v-1].Dv) {
                vvv[head->v-1].Dv = vvv[v].Dv + head->w;
                vvv[head->v-1].Pv = v + 1;
            }
            head = head->next;
        }
    }

    showTable(vvv);

   






}

void addLink(MapNode* root, vector<vector<int>> vec) {
    if(vec.size() == 0) { return;}
    root->next = new MapNode(vec.back()[0], vec.back()[1]);
    
    
    vec.pop_back();
    addLink(root->next, vec);
}

void showTable(vector<NWNode>& vNw) {
    cout << "# vNw Table #" << endl;
    cout << "V  | Known | Dv | Pv" << endl;
    cout.setf(ios_base::boolalpha);
    cout.setf(ios_base::left, ios_base::adjustfield);

    for(int i = 0; i < 7; i++) {
        cout.width(4);
        cout << i + 1;

        cout.width(8);
        cout << vNw[i].Known;

        cout.width(6);
        cout << vNw[i].Dv;

        cout.width(4);
        cout << vNw[i].Pv << endl;
    }
}

int findSmallestUnknownNode(vector<NWNode>& nwn) {
    int res = -1;
    for(int i = 0; i < 7; i++) {
        if(nwn[i].Known == false && (res == -1 || nwn[i].Dv < nwn[res].Dv)) {
            res = i;
        }
    }
    return res;
}




   



  























