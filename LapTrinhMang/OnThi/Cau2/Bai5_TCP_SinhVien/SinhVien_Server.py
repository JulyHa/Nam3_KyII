import socket

host = '127.0.0.1'
port =5051

sinhvien = {"M01":"Ngũ", "M02":"Khải", "M03":"Thiên An"}

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    sk.bind((host, port))
    sk.listen(5)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    client, addr = sk.accept()
    client.send("Hello client".encode('utf-8'))
    data = client.recv(1024).decode('utf-8')
    print(data)
    client.send("Nhập 1 để bắt đầu!".encode('utf-8'))

    while True:
        data = client.recv(1024).decode('utf-8')
        if data == '1':
            client.send("Nhập mã sinh viên! ".encode('utf-8'))

            data = client.recv(1024).decode('utf-8')
            try:

                msg = sinhvien[data] + "!q"
                client.send(msg.encode('utf-8'))
            except:
                client.send("Không có sinh viên nào!q".encode('utf-8'))
            finally:
                break
        else:
            client.send("Nhập 1 để bắt đầu! ".encode('utf-8'))