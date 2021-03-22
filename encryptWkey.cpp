#include <iostream>
#include <string>

int enChar(int in, int key, int m){
    int ret = in - 4*m*key;
    while(ret<32 || ret>=126){
        ret = 126-(32-ret);
    }
    return ret;
}

int decChar(int in, int key, int m){
    int ret = in + 4*m*key;
    while(ret<32 || ret>=126){
        ret = 32+(ret-126);
    }
    return ret;

}




std::string encrypt(const std::string& in, std::string &key){
std::string temp;
int j = 0;
for (unsigned int i = 0; i<in.size();i++){
        temp+=(char)enChar((int)in[i] ,(int)key[j], key.size());
        j<=key.size()? j++ : j=0;
}
return temp;
}

std::string decrypt(const std::string& in, std::string& key){
std::string temp;
int j = 0;
for (unsigned int i = 0; i<in.size();i++){
        temp+=(char)decChar((int)in[i] ,(int)key[j], key.size());
        j<=key.size()? j++ : j=0;
}
key = encrypt(key, key);
return temp;
}


int main(){
std::string s;
std::string key = "v3ry~!@str0NG/'K3Y!??";
getline(std::cin, s);

std::string g = encrypt(s, key);
std::cout << g << "\n";

std::string l = decrypt(g, key);
std::cout << l << "\n";

g = encrypt(l, key);
std::cout << g << "\n";

l = decrypt(g, key);
std::cout << l << "\n";


return 0;
}

