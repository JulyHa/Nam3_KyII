import socket


host = '127.0.0.1'
port = 5050
if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    data, addr = sk.accept()

    print("Thông tin client: ", addr)

    lenh = data.recv(1024).decode('utf-8')

    so = data.recv(1024).decode('utf-8')
    try:
        so = so.split(' ')
        a = int(so[0])
        b = int(so[1])

        if lenh == "Max":
            res = max(a, b)
        else:
            res = min(a, b)
        msg = str(res)
        data.send(msg.encode('utf-8'))
    except:
        msg = "Lỗi!"
        data.send(msg.encode('utf-8'))

    sk.close()