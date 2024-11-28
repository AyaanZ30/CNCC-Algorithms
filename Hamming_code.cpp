# include <iostream>
# include <string> 
# include <vector>
# include <math.h>

using namespace std;

int calculate_Parity(vector<int> encoded_data, int position){
    int parity = 0;
    for(int i = position - 1 ; i < encoded_data.size() ; i += (2 * position)){
        for(int j = i ; j < i + position && j < encoded_data.size() ; j++){
            parity ^= encoded_data[j];
        }
    }return parity;
}
vector<int> Hamming_Encode(const vector<int> &data){
    vector<int> encoded_data(7, 0); 
    encoded_data[2] = data[0]; 
    encoded_data[4] = data[1];
    encoded_data[5] = data[2];
    encoded_data[6] = data[3];

    encoded_data[0] = calculate_Parity(encoded_data, 1);
    encoded_data[1] = calculate_Parity(encoded_data, 2);
    encoded_data[3] = calculate_Parity(encoded_data, 4);
    return encoded_data;
}
vector<int> Hamming_Decode(vector<int> &data){
    int error_position = 0;
    for(int i = 0 ; i < 3 ; i++){                       // 3 parity bits => 3 combinations of error pos possible
        int parity = calculate_Parity(data, pow(2, i));
        if(parity != 0){
            error_position += pow(2, i);
        }
    }
    if(error_position != 0){
        cout << "Error detected at position " << error_position << " in received data" <<endl;
        data[error_position - 1] ^= 1;
        cout << "Correctly received 7 bit data ";
        for(int bit : data){
            cout << bit << " ";
        }
    }else{
        cout << "No error detected in received data" << endl;
    }
    return {data[2], data[4], data[5], data[6]};
}
int main(){
    vector<int> data(4);
    cout << "Enter 4 data bits (seperated by spaces) : ";
    for(int i = 0 ; i < 4 ; i++){
        cin  >> data[i];
    }
    vector<int> encoded_data = Hamming_Encode(data);
    cout << "Encoded Data : ";
    for(int bit : encoded_data){
        cout << bit << " ";
    }
    vector<int> received_data;
    cout << "\nEnter received data (post-transmission) : ";
    for(int i = 0 ; i < 7 ; i++){
        cin >> received_data[i];
    }
    vector<int> decoded_data = Hamming_Decode(received_data);
    cout << "Decoded Data (4-bits): ";
    for(int bit : decoded_data){
        cout << bit << " ";
    }
    return 0;
}