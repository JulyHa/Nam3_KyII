import socket

host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host,port))

    data, addr = sk.recvfrom(1024)

    msg = data.decode('utf-8')
    print(msg)

    msg.strip()
    s = msg.split(" ")
    msg = ""
    for i in s:
        if i != "":
           msg += i
    ok = 1
    res = ""
    for i in msg:
        if ok == 1:
            res +=  i.upper()
            ok = 0
        elif i == '.':
            ok = 1
            res += i + ' '
        else:
            res += i
    sk.sendto(res.encode('utf-8'), addr)