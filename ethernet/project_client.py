import socket
import threading

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Specify the server IP and port number to connect to
ip = socket.gethostname()
port = 1234

# Connect to the server
s.connect((ip, port))

# Receive message from the server
message = ""

def rec_host():
    global message
    while 1:
        message = s.recv(1024)
        print(message.decode())

def send_host():
    global message
    while 1:
        message = input("enter message: ")
        s.send(message.encode("utf-8"))

def s_r():
    thread_1 = threading.Thread(target=rec_host)
    thread_2 = threading.Thread(target=send_host)

    thread_1.start()
    thread_2.start()

    thread_1.join()
    thread_2.join()

while True:
    s_r()

# Close the connection
# s.close()