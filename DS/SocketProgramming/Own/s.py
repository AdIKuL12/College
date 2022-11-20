import socket
import sys


def server():
    try:
        ss = socket.socket()
        print("successfully created")
    except socket.error as se:
        print("error %s" % (se))

    try:
        host = "127.0.0.1"
        port = 3000
    except socket.gaierror:
        print("error in resolving host")
        sys.exit()

    try:
        ss.bind((host, port))
        print("binding successful")
    except Exception as e:
        print("binding unsuccessful", e)

    try:
        ss.listen(10)
    except Exception as e:
        print("listening error", e.__class__)

    try:
        conn, addr = ss.accept()
        print("connection established with " + str(addr))
    except InterruptedError as ie:
        print("Error while accepting connection", ie.__class__)
    except Exception as e:
        print("error while accepting the connection", e.__class__)

    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        print("from connected user " + str(data))
        data = input("-> ")
        conn.send(data.encode())
    conn.close()
    ss.close()


server()
