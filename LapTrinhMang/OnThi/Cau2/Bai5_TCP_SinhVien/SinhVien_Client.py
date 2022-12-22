import socket

host = '127.0.0.1'
port =5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    sk.connect((host, port))
    sk.send("Hello server".encode('utf-8'))
    data = sk.recv(1024).decode('utf-8')
    print(data)
    data = sk.recv(1024).decode('utf-8')
    print(data)

    while True:
        msg = input()
        sk.send(msg.encode('utf-8'))
        data = sk.recv(1024).decode('utf-8')
        s = data.split("!")
        print(s[0])
        if s[1] == 'q':
            break

