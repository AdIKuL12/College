import socket
import sys


def server():

    # Creating socket for server to listen and accept
    try:
        server_socket = socket.socket()
        print("Socket created successfully\n")
    except socket.error as err:
        print("Error while creating the socket %s" % (err))

    # Getting host and port for establishing the connection
    try:
        # host = socket.gethostbyname("localhost")
        host = "127.0.0.1"
        port = 5000
    except socket.gaierror:
        print("There was an error resolving the host")
        sys.exit()

    # Binding the socket with host adders and port
    try:
        server_socket.bind((host, port))
        print("Binding of server socket successful")
    except Exception as e:
        print("Socket binding unsuccessful ", e._class_)

    # Enable a server to accept connections.
    # If backlog is specified, it must be at least 0 (if it is lower, it is set to 0);
    #  it specifies the number of unaccepted connections that the system will allow
    # before refusing new connections. If not specified, a default reasonable value is chosen.
    try:
        server_socket.listen(10)
    except Exception as e:
        print("Error while listening ", e._class_)

    # Accept a connection. The socket must be bound to an address and listening for connections.
    # The return value is a pair (conn, address) where conn is a new socket object usable to send
    # and receive data on the connection, and address is the address bound to the socket
    # on the other end of the connection.
    try:
        conn, addr = server_socket.accept()
        print("Connection established with : " + str(addr))
        # print(type(conn), ' ', type(addr),'\n')
    except InterruptedError as ie:
        print("Error accepting the connection ", ie._class_)
    except Exception as e:
        print("Error while accepting the connection", e._class_)

    while True:
        # Receive data from the client
        # Maximum data packet size is 1024
        data = conn.recv(1024).decode()

        # if not data is received then break
        if not data:
            break

        print("from connected user: " + str(data))

        # sending the data
        data = input("-> ")
        conn.send(data.encode())

    # Close the connection
    conn.close()
    server_socket.close()


server()
