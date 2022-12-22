import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    while True:
        r = input("Nhập 'r' để connect! ")
        if(r == 'r'):
            break
    sk.connect((host, port))
    sk.send("Hello sever".encode('utf-8'))

    data = sk.recv(1024)
    print("Data from server: %s" % data.decode('utf-8'))

    data = input("Nhập opt, a, b, c:   ")
    sk.send(data.encode('utf-8'))

    data = sk.recv(1024)
    print("Data from server: %s" % data.decode('utf-8'))

    sk.close()
