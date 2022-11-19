import socket
import sys


def client():

    # Creating socket at host for communication with server
    try:
        client_socket = socket.socket()
        print("Client socket created successfully")
    except socket.error as err:
        print("Client socket creation error %s" % (err))

    # Getting the host and address for establising the connection
    try:
        # host = socket.gethostbyname('localhost')
        host = '127.0.0.1'
        port = 5000
    except socket.gaierror:
        print("Error resolving the host at client")

    # Establishing the connection with the server
    # Connect to a remote socket at address. (The format of address depends on the address family)
    try:
        client_socket.connect((host, port))
        print("Connection of client with server successfull")
    except TimeoutError as toe:
        print("Connection timed out: ", toe._str_)
    except InterruptedError as ie:
        print("Connection with server unsuccessfull due to ie ", ie._class_)
    except Exception as e:
        print("Connection with server unsuccesfull due to e ", e._class_)

    # Message to be sent to the client
    message = input("-> ")

    while message.lower().strip() != 'exit':
        # send message to server
        client_socket.send(message.encode())

        # receive response from the server
        data = client_socket.recv(1024).decode()
        print("Received from server: " + str(data))

        message = input("-> ")

    # Closing the client socket
    client_socket.close()


client()
