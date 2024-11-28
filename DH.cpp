# include <iostream>
# include <cstdlib>
# include <string>

using namespace std;

int mod_exp(int base, int power, int n){
    int result = 1;
    base = (base % n);
    while(power > 0){
        if((power % 2) == 1){
            result = (result * base) % n;
        }
        power /= 2;
        base = (base * base) % n;
    }return result;
}
void CompareKeys(int k1, int k2){
    if(k1 == k2){
        cout << "Key exchange successful" << endl;
    }else{
        cout << "Key exchange failed" << endl;
    }
}
string XOR(string data, int key){
    for(char &c : data){
        c ^= key;
    }return data;
}
void XOR_Encrypt_Decrypt(int k1, int k2, string message){
    if(k1 == k2){
        int shared_secret = k1;
        cout << "Original message : " << message << endl;

        string encrypted_message = XOR(message, shared_secret);
        cout << "Encrypted message : " << encrypted_message << endl;

        string decrypted_message = XOR(encrypted_message, shared_secret);
        cout << "Decrypted message : " << decrypted_message << endl;
    }  
}
void Deffie_Hellman(int p, int g, string message){
    int a = rand() % (p - 1) + 1; // Secret key for Alice
    int b = rand() % (p - 1) + 1; // Secret key for Bob

    int alice_public_key = mod_exp(g, a, p);
    int bob_public_key = mod_exp(g, b, p);

    cout << "Alice's public key (g^a mod p) : " << alice_public_key << endl;
    cout << "Bob's public key (g^b mod p) : " << bob_public_key << endl;

    int alice_secret_key = mod_exp(bob_public_key, a, p);
    int bob_secret_key = mod_exp(alice_public_key, b, p);

    cout << "Alice's secret key  : " << alice_secret_key << endl;
    cout << "Bob's secret key  : " << bob_secret_key << endl;

    CompareKeys(alice_secret_key, bob_secret_key);
    XOR_Encrypt_Decrypt(alice_secret_key, bob_secret_key, message);
}
int main(){
    int p, g;
    cout << "Enter a prime number (agreeable to both parties) : ";
    cin >> p;
    cout << "Enter the generator value : "; 
    cin >> g;

    string message = "Bhavvya Gay";

    Deffie_Hellman(p, g, message);
    return 0;
}