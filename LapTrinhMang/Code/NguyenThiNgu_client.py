import socket
if __name__=="__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    sk.connect((host,port))

    data = input("Nhap mess: ")
    sk.send(data.encode('utf-8'))
    data = sk.recv(1024)
    print("Data from client: %s"%data.decode('utf-8'))
    sk.close()
