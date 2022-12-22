import socket

host = "127.0.0.1"
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    print("Chờ client kết nối!")

    while True:
        data, addr = sk.recvfrom(1024)
        if data.decode('utf-8') == 'r':
            msg = "1. Cộng 2.Trừ"
            sk.sendto(msg.encode('utf-8'), addr)

        else:
            s = data.decode('utf-8').split(' ')
            if int(s[0]) == 1:
                msg = int(s[1]) + int(s[2]) + int(s[3])
            else:
                msg = int(s[1]) - int(s[2]) - int(s[3])
            data = str(msg)
            sk.sendto(data.encode('utf-8'), addr)
            break
