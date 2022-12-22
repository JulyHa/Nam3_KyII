from time import ctime
import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    while (True):
        print("waiting for client")
        client, addr = sk.accept()
        print("Client address ", addr)
        # nhan du lieu
        print(client.recv(1024).decode('utf-8'))
        client.send("hi".encode('utf-8'))
        data = client.recv(1024)
        if not data:
            break
        so = data.decode('utf-8')
        s = so.split(' ')
        if (s[3] == '+'):
            tong = float(s[0]) + float(s[2]) + float(s[1])
        if (s[3] == '-'):
            tong = float(s[0]) - float(s[2]) - float(s[1])
        if (s[3] == '/'):
            tong = float(s[0]) / float(s[2]) / float(s[1])
        if (s[3] == '*'):
            tong = float(s[0]) * float(s[2]) * float(s[1])
        data = str(tong)
        client.send(data.encode('utf-8'))
        client.send("Ban co muon tiep tuc khong?".encode('utf-8'))
        data = client.recv(1024)
        if data.decode('utf-8') == "no":
            break
        else:
            client.send("moi ban nhap tiep".encode('utf-8'))
        client.close()
    sk.close()