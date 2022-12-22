import socket

host = "127.0.0.1"
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    while True:
        msg = input("Nhập r để kết nối: ")
        if msg == 'r':
            sk.sendto(msg.encode('utf-8'), (host, port))
            break

    data, addr = sk.recvfrom(1024)
    print("Sever gửi: " + data.decode('utf-8'))

    msg = input("Nhập opt, a, b, c: ")
    sk.sendto(msg.encode('utf-8'), (host, port))

    data, addr = sk.recvfrom(1024)
    print("Sever gửi kết quả: " + data.decode('utf-8'))

