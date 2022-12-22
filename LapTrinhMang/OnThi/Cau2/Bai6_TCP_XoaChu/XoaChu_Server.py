import socket

host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    data, addr = sk.accept()

    msg = data.recv(1024).decode('utf-8')

    #chuan hoa
    msg = msg.strip() # xóa các đầu cuối

    s = msg.split(" ")
    res = ""
    for i in s:
        if i != "":
            res += i
    msg = ""
    ok = 1
    for i in res:
        if ok == 1:
            msg += i.upper()
            ok = 0
        elif i == ".":
            msg += i
            ok = 1
        else:
            msg += i

    data.send(msg.encode('utf-8'))