import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    sk.connect((host, port))
    sk.send("Hello sever".encode('utf-8'))
    while True:

        data = input("Nhập chuỗi ký tự:  ")
        sk.send(data.encode('utf-8'))

        data = sk.recv(1024)
        print("Data from server: %s" % data.decode('utf-8'))
        data = sk.recv(1024)
        print("Data from server: %s" % data.decode('utf-8'))
        data = input()
        sk.send(data.encode('utf-8'))
        if data == "no":
            break

    sk.close()
