import socket
SERVER = "127.0.0.1"
PORT = 8080
client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect((SERVER,PORT))

while True:
    i = input("Enter an Equation")
    if i == "-1":
        break
    client.send(i.encode())

    ans = client.recv(1024)
    print("Ans => " + ans.decode())
    print("-1 to exit")
client.close()