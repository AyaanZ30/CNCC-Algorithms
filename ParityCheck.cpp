# include <iostream>
# include <string>

using namespace std;

int calculate_Parity_Bit(string data){
    int count = 0;
    for(const char x : data){
        if(x == '1'){
            count += 1;
        }
    }
    return ((count % 2) == 0) ? '0' : '1';
}
bool check_Parity(string received_data){
    string data = received_data.substr(0, received_data.length() - 1);
    char received_parity = received_data.back();
    char calculated_parity = calculate_Parity_Bit(data);

    return (received_parity == calculated_parity);
}

int main(){
    string data;
    cout << "Enter Binary Data : ";
    cin >> data;

    char parity_bit = calculate_Parity_Bit(data);
    cout << "Parity bit for data : " << parity_bit << endl;

    string transmitted_data = data + parity_bit;
    cout << "Transmitted data : " << transmitted_data << endl;

    string receivedData;
    cout << "Enter received data: ";
    cin >> receivedData;

    if(check_Parity(receivedData)){
        cout << "Parity check passed (NO ERROR IN TRANSMISSION)" << endl;
    }else{
        cout << "Parity check failed (ERROR IN TRANSMISSION)" << endl;
    } 
    return 0;
}