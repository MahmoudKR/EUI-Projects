import socket
import threading

clients = []
addresses = []
message = 1

def c1():
    while True:
        cl = clients[0]
        message = cl.recv(1024)
        print(message.decode())

def c2():
    while True:
        cl = clients[1]
        message = cl.recv(1024)
        print(message.decode())

def c3():
    while True:
        cl = clients[2]
        message = cl.recv(1024)
        print(message.decode())

def send_client(clients):
    while True:
        index = input("enter client number: ")
        message = input("enter message: ")
        client = clients[int(index)]
        client.send(message.encode())


def recv_send_client():
    print("receiving from clients")
    thread_1 = threading.Thread(target=c1)
    thread_2 = threading.Thread(target=c2)
    thread_3 = threading.Thread(target=c3)
    thread_4 = threading.Thread(target=send_client, args=(clients,))

    thread_1.start()
    thread_2.start()
    thread_3.start()
    thread_4.start()

    thread_4.join()
    thread_1.join()
    thread_2.join()
    thread_3.join()

def close_connections():
    for client in clients:
        client.close()

def broadcast(message):
    for client in clients:
        client.send(message.encode())

def accept_connections():
    print("Waiting for clients to connect...")
    for i in range(3):
        client, address = s.accept()
        clients.append(client)
        addresses.append(address)
        print(f"Client {i} is connected with address {address}")

# Create a socket and set it up for accepting connections
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostname()
port = 1234
# bind the socket to the IP address and port
s.bind((ip, port))
s.listen(3)

accept_connections()

while True:
    print("select mode: 1:broadcast 2:send to client 3:close connections")
    mode = int(input("enter mode: "))

    if mode == 1:
        message = "mostafa"
        while message != "exit":
            print("*broadcast mode*")
            message = input("enter message: ")
            broadcast(message)
    elif mode == 2:
        print("send/receive mode")
        while (message != "exit"):
            recv_send_client() 
    elif mode == 3:
        break

close_connections()

# Close the server socket
s.close()