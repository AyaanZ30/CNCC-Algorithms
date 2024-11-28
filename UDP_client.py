import socket 

PORT = 8080

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

message = "Hello from CLIENT"
client_socket.sendto(message.encode(), ('localhost', PORT))
print(f'Message sent to server from client : {message}')

try:
    response, server_addr = client_socket.recvfrom(1024)
    print(f'Response from server to client : {response.decode()}')
except Exception as e:
    print(f'An error occurred : {e}')
    
client_socket.close()