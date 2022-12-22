from time import ctime
import socket
if __name__=="__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    host = 'localhost'
    port = 5050
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    while(True):
        print("waiting for client")
        client,  addr = sk.accept()
        print("Client address ", addr)
        #nhan du lieu
        data = client.recv(1024)
        if not data:
            break
        file_name = data.decode('utf-8')
        try:
            f = open(file_name, 'rb')
            res = f.read()
        except:
            res = "Not file"
        client.send(res)

        client.close()
    sk.close()