import socket


host = '127.0.0.1'
port = 5050
if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)

    sk.connect((host, port))

    msg = input("Nhập Max/Min: ")
    sk.send(msg.encode('utf-8'))

    msg = input("Nhập 2 số a b: ")
    sk.send(msg.encode('utf-8'))

    data = sk.recv(1024).decode('utf-8')
    print("Server trả kết quả: " + data)
