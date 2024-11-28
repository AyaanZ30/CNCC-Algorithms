#include <iostream>
#include <string>

using namespace std;

string XOR(string n1, string n2) {
    string res = "";
    for (size_t i = 1; i < n2.length(); i++) {
        res += (n1[i] == n2[i]) ? '0' : '1';
    }
    return res;
}
string mod_2_division(string data, string divisor) {
    int division_window = divisor.length();
    string temp = data.substr(0, division_window);

    while (division_window < data.length()) {
        if (temp[0] == '1') {
            temp = XOR(temp, divisor) + data[division_window];
        } else {
            temp = XOR(temp, string(divisor.length(), '0')) + data[division_window];
        }
        division_window++;
    }
    if (temp[0] == '1') {
        temp = XOR(temp, divisor);
    } else {
        temp = XOR(temp, string(divisor.length(), '0'));
    }return temp;
}
bool corruption_check(string received_data, string divisor) {
    string remainder = mod_2_division(received_data, divisor);
    for (char bit : remainder) {
        if (bit == '1') {
            return true; 
        }
    }return false; 
}

int main() {
    string data = "101010";
    string divisor = "110";

    cout << "Data: " << data << endl;
    cout << "Divisor: " << divisor << endl;

    string paddedData = data + string(divisor.length() - 1, '0');
    cout << "Padded Data: " << paddedData << endl;

    string CRC_value = mod_2_division(paddedData, divisor);
    cout << "CRC Value: " << CRC_value << endl;

    string transmitted_data = data + CRC_value;
    cout << "Transmitted Data: " << transmitted_data << endl;

    transmitted_data[2] = (transmitted_data[2] == '0') ? '1' : '0'; // Flip a bit to simulate error
    cout << "Received Data (with error): " << transmitted_data << endl;

    if (corruption_check(transmitted_data, divisor)) {
        cout << "Data is corrupted!" << endl;
    } else {
        cout << "Data is intact." << endl;
    }

    return 0;
}
