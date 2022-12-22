import socket

host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    sk.connect((host, port))

    msg = input("Nhập chuỗi: ")
    sk.send(msg.encode('utf-8'))

    msg = sk.recv(1024)
    print(msg.decode('utf-8'))
