import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    print("Waiting for client!")
    client, addr = sk.accept()
    print("Client address: ", addr)
    # Nhận dữ liệu
    print("Data from client: %s" % client.recv(1024).decode('utf-8'))
    client.send("Hello client!".encode('utf-8'))

    data = client.recv(1024)
    so = data.decode('utf-8')
    s = so.split(' ')
    res = max(s[0], s[1])
    client.send(res.encode('utf-8'))
    client.close()

    sk.close()