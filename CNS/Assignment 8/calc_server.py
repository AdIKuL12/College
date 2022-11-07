import socket
LOCALHOST = "127.0.0.1"
PORT = 8080

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind((LOCALHOST,PORT))
server.listen(1)

print("Server has Started")
print("Waiting for Response")

c_conn,c_addr = server.accept()
print("connected client => ",c_addr)
msg = ''

while True:
    # data = data+ (pad * chr(pad))
    data = c_conn.recv(1024)
    msg = data.decode()
    if msg == "-1":
        print("Connection is Over")
        break
    print("Equ is Received")
    res = 0
    op_list = msg.split()
    op1 = op_list[0]
    operator = op_list[1]
    op2 = op_list[2]

    num1 = int(op1)
    num2 = int(op2)
    if operator == "+":
        res = num1 + num2
    elif operator == "-":
 
        res = num1 - num2
    elif operator == "/":
        res = num1 / num2
    elif operator == "*":
        res = num1 * num2

    print("Send Result to Client")
    op = str(res)
    c_conn.send(op.encode())
c_conn.close()