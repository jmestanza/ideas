#include <bits/stdc++.h> 
using namespace std;
// https://www.hackerrank.com/challenges/attribute-parser/problem
void print_map(map<string,string> const &m)
{
	for (auto const& pair: m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}

map<string,string> tagMap;

string slice_string(string input,int a,int b){ // de [a,...,b]
    if(b>=0){
        return input.substr(a,(b-a)+1);
    }else{
        return input.substr(a, input.size()+b); // si pongo b = -1, voy hasta el ultimo inclusive.
    }
}

int main(){
    int N,Q;
    string query;
    string key,value;
    string attrib,val,equal_symbol,tag_or_endtag;
    string tag_of_endtag;
    string tag_of_opentag;
    vector<string> ans;
    cin >> N >> Q;
    string current_pretag = "";
    for(int i = 0 ; i < N ; i++){
        cin >> tag_or_endtag;
        if(tag_or_endtag[1] == '/'){ // found endtag
            tag_of_endtag = slice_string(tag_or_endtag,2,tag_or_endtag.size()-1);
            if(current_pretag.find('.')!= string::npos){
                current_pretag = slice_string(current_pretag,0,(current_pretag.size()-1)-(tag_of_endtag.size()-1+1)); // +1 por '.'
            }else{
                current_pretag = ""; // si no tiene '.' y llego un endtag => pretag debe ser vacio
            }
            
        }else{ // found open tag
            // puede ser un tag q no tiene atributes.
            if(tag_or_endtag.find('>') != string::npos){ // <tag1>
                // no hago nada, pero tengo que agregarlo como pretag
                tag_of_opentag = slice_string(tag_or_endtag,1,-2); // hasta el anteultimo incluido
                current_pretag += (current_pretag==""?"":".") + tag_of_opentag;
            }else{// <tag1
                tag_of_opentag = slice_string(tag_or_endtag,1,-1); // hasta el final
                cin >> attrib >> equal_symbol >> val;
                current_pretag += (current_pretag==""?"":".") + tag_of_opentag;
                while(!(val.find('>') != string::npos)){ // while not found '>'
                    // "HelloWorld" 
                    val = slice_string(val,1, -2); 
                    tagMap[current_pretag+"~"+attrib] = val;
                    cin >> attrib >> equal_symbol >> val;
                }
                // "Name1">
                val = slice_string(val,1, -3);
                tagMap[current_pretag+"~"+attrib] = val;
            }    
        }
    }
    for(int i = 0 ; i < Q ; i++){
        cin >> query;
        size_t found = query.find("~");
        key = query.substr(0,found);
        value = query.substr(found+1); // desde found+1 hasta el final 
        if( tagMap.find(key+"~"+value) == tagMap.end()){ // si no existe la key
            ans.push_back("Not Found!");
        }else{
            ans.push_back(tagMap[key+"~"+value]);
        }
    }
    for(auto &s:ans){
        cout << s << endl;
    }
    // print_map(tagMap);
    return 0;
}