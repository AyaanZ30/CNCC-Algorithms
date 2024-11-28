# include <iostream>
# include <cmath>
# include <cstdlib>

using namespace std;

int GCD(int x, int y){
    while(y != 0){
        int current_divisor = y;
        y = (x % y);
        x = current_divisor;
    }return x;
}
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
void RSA(int p, int q, int message){
    cout << "Primes : " << "p = " << p << " q = " << q << endl;
    int n = (p * q);

    int phi;
    phi = (p - 1) * (q - 1);
    
    int e = 2;                                // encryption value such that 1 < e < phi and gcd(phi, e) = 1
    while(e < phi && GCD(phi, e) != 1){
        e++;
    }

    int d = 1;                                // d => private key such that (d * e) % phi == 1
    while((d * e) % phi != 1){
        d++;
    }

    cout << "Public key : " << "( " << e << "," << n << " )" << endl;
    cout << "Private key : " << "( " << d << "," << n << " )" << endl;

    cout << "Original message : " << message << endl;

    int encrypted_message = mod_exp(message, e, n);                    // encrypted c = (message^e) % n
    cout << "Encrypted message : " << encrypted_message << endl;
    int decrypted_message = mod_exp(encrypted_message, d, n);           // decrypted p = (c ^ d) % n; (c -> above encrypted message)
    cout << "Decrypted message : " << decrypted_message << endl;
}
int main(){
    int p, q, message;
    cout << "Enter p = ";
    cin >> p;
    cout << "Enter q = ";
    cin >> q;
    cout << "Enter message = ";
    cin >> message;

    RSA(p, q, message);
    return 0;
}