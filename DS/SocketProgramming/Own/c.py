import sys
import socket


def client():
    try:
        cs = socket.socket()
        print("Socket created successfully")
    except socket.err as e:
        print("socket creation error %s" % (e))

    try:
        host = "127.0.0.1"
        port = 3000
    except socket.gaierror:
        print("host resolving error")

    try:
        cs.connect((host, port))
        print("connection successfull")
    except TimeoutError as toe:
        print("connection timed out", toe.__str__)
    except InterruptedError as ie:
        print("connection unsuccessful due to ie", ie.__class__)
    except Exception as e:
        print("connection unsuccessful due to e", e.__class__)

    msg = input("-> ")

    while msg.lower().strip() != 'exit':
        cs.send(msg.encode())
        data = cs.recv(1024).decode()
        print("received from server" + str(data))
        msg = input("-> ")

    cs.close()


client()
