import socket 

PORT = 8080

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_socket.bind(('localhost', PORT))
print(f'Server listening on port {PORT}')

while True:     # while the connection lasts 
    try:
        data, client_addr = server_socket.recvfrom(1024)
        print(f'Received from {client_addr} : {data.decode()}')
        
        response = "Hello from SERVER"
        server_socket.sendto(response.encode(), client_addr)
        print(f'Response sent from server to client at {client_addr} : {response}')
    except Exception as e:
        print(f'Error occurred : {e}')
    
