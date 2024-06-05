#include <iostream>
#include <map>
using namespace std;

int main(){
    string op;
    map<string, string> m;
    while(cin >> op){
        
        //ESCRIBIR
        if(op == "info"){
            cout << "PARELLES:" << endl;
            for(map<string,string>::iterator it = m.begin(); it != m.end(); ++it){
                if(it->second != "" and it->first < it->second) cout << it->first << " " << it->second << endl;
                //if(it->second != "" and it->first > it->second) cout << it->second << " " << it->first << endl;
             }


            cout << "SOLS:" << endl;
            for(map<string,string>::iterator it = m.begin(); it != m.end(); ++it){
                if(it->second == "") cout << it->first << endl;
            }
            cout << "----------" << endl;
        }

        else{
            string x, y;
            cin >> x >> y;
            //insertar SEMPRE la parella 2 vegades, de les dues maneres

            //CASO X
            map<string,string>::iterator it_x = m.find(x);
            if(it_x == m.end()) m.insert({x,y});
            else{
                //si trobar i s'ha quedat solter
                if(it_x->second == "") it_x->second = y;
                //si trobar i te parella
                else{
                    //busquem la parella de x que es quedara soltera
                    map<string,string>::iterator it1 = m.find(it_x->second);
                    it1->second = "";
                    it_x->second = y;

                }
            }

            //CASO Y
            map<string,string>::iterator it_y = m.find(y);
            if(it_y == m.end()) m.insert({y,x});
            else{
                //ja tenia una parella
                if(it_y->second == "") it_y->second = x;
                else{
                    map<string,string>::iterator it2 = m.find(it_y->second);
                    it2->second = "";
                    it_y->second = x;
                }
            }
        }
    }
}