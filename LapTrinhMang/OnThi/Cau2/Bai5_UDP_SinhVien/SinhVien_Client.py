import socket

host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    msg = "Hello server!"
    sk.sendto(msg.encode('utf-8'), (host, port))

    data, addr = sk.recvfrom(1024)
    data = data.decode('utf-8')
    print("Server gửi: " + data)

    data, addr = sk.recvfrom(1024)
    data = data.decode('utf-8')
    print("Server gửi: " + data)
    while True:
        msg = input()
        sk.sendto(msg.encode('utf-8'), (host, port))
        data, addr = sk.recvfrom(1024)
        data = data.decode('utf-8')
        s = data.split("!")
        print("Server gửi: " + s[0])
        if s[1] == 'q':
            break
