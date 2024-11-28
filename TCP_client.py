import socket 

PORT = 8080

def start_TCP_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    client_socket.connect(('localhost', PORT))
    print(f"Connected to server at port : {PORT}")
    
    message = "Hello from Client"
    client_socket.send(message.encode())
    print(f"Message sent from client --> server")
    
    server_response = client_socket.recv(1024)
    print(f'Server response : {server_response.decode()}')
    
    client_socket.close()
    
if __name__ == '__main__':
    start_TCP_client()