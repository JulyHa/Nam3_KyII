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

        s = data.decode('utf-8')
        s = s.replace("  ", " ")
        s = s.replace(" ,", ",")
        s = s.replace(" .", ".")
        res = s[0]+s[1]
        for i in range(2, len(s)):
            if s[i - 2] == '.' and s[i] >= 'a':
                res += chr(ord(s[i]) - 32)
            else:
                res += s[i]

        client.send(res.encode('utf-8'))

        client.close()
    sk.close()