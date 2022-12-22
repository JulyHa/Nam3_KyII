import socket

host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    print("Chờ client kết nối!")


    data, addr = sk.recvfrom(1024)

    print("Kết nối từ: {}".format(addr))
    data = data.decode('utf-8')
    s = data.split(',')
    if s[0] == "LO":
        print("Client nhập: LO")
        msg = s[1].lower()
    else:
        print("Client nhập UP")
        msg = s[1].upper()
    sk.sendto(msg.encode('utf-8'), addr)