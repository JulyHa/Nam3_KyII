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
        print("Data from client: %s" %client.recv(1024).decode('utf-8'))
        client.send("Hello client".encode('utf-8'))
        data = client.recv(1024)
        if not data:
            break
        so = data.decode('utf-8')
        count =0
        for x in so:
            if x.isupper():
                count += 1
        data = str(count)
        client.send(data.encode('utf-8'))
        client.send("Bạn có muốn tiếp tục không?".encode('utf-8'))
        data = client.recv(1024)
        if data.decode('utf-8') == "no":
            break
        else:
            client.send("Mời bạn nhập tiếp: ".encode('utf-8'))
        client.close()
    sk.close()