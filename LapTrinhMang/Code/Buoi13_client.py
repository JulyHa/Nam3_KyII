import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5051
    sk.connect((host, port))
    while True:
        sk.send("hi".encode('utf-8'))
        data = input("Nhap a, b, c, op: ")
        sk.send(data.encode('utf-8'))

        data = sk.recv(1024)
        print("Data from client: %s" % data.decode('utf-8'))
        data = sk.recv(1024)
        print("Data from client: %s" % data.decode('utf-8'))
        data = input()
        sk.send(data.encode('utf-8'))
        if data == "no":
            break

    sk.close()