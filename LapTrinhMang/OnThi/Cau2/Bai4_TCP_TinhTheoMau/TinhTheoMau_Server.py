from time import ctime
import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5051
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    print("waiting for client")
    client, addr = sk.accept()
    print("Client address ", addr)

    print("Data from client: %s" %client.recv(1024).decode('utf-8'))
    client.send("\n1. Cộng \n2. Trừ".encode('utf-8'))

    # nhan du lieu
    data = client.recv(1024)
    so = data.decode('utf-8')
    s = so.split(" ")
    res = 0
    a = float(s[1])
    b = float(s[2])
    c = float(s[3])
    if s[0] == "1":
        res = a + b + c
    if s[0] == "2":
        res = a - b - c
    data = str(res)
    client.send(data.encode('utf-8'))
    client.close()
    sk.close()