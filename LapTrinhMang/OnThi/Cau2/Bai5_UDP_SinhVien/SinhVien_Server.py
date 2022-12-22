import socket

host = '127.0.0.1'
port = 5051

sinhvien = {"M01":"Ngũ", "M02":"Khải", "M03":"Thiên An"}

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))

    data, addr = sk.recvfrom(1024)
    data = data.decode('utf-8')
    print("Client gửi: " + data)
    msg = "Hello client!"
    sk.sendto(msg.encode('utf-8'), addr)
    msg = "Nhập 1 để bắt đầu!"
    sk.sendto(msg.encode('utf-8'), addr)
    while True:
        data, addr = sk.recvfrom(1024)
        data = data.decode('utf-8')
        if data == '1':
            msg = "Nhập mã sinh viên!"
            sk.sendto(msg.encode('utf-8'), addr)

            data, addr = sk.recvfrom(1024)
            data = data.decode('utf-8')

            try:
                msg = sinhvien[data] + "!q"
                sk.sendto(msg.encode('utf-8'), addr)
            except:
                msg ="Không có sinh viên!q"
                sk.sendto(msg.encode('utf-8'), addr)

            break
        else:
            msg = "Nhập 1 để bắt đầu!"
            sk.sendto(msg.encode('utf-8'), addr)
