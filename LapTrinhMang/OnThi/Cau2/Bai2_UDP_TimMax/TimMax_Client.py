import socket

host = "127.0.0.1"
port = 9050

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    msg = "hello"

    while True:
        msg = input("Client: ")
        sk.sendto(msg.encode('utf-8'), (host, port))
        if msg == "q":
            break
        data, addr = sk.recvfrom(1024)
        print("Sever gui: " + data.decode('utf-8'))
        msg = "Nhan q de thoat"