# Xây dựng base module

import socket
import ssl

host = '127.0.0.1'
port = 9051

def create_socket(host, port):
    sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sk.bind((host, port))
    sk.listen(10)
    return  sk

def recv_msg(sk):
    #Nhận cho đến khi gặp null (\0)
    data = bytearray()
    msg = ''
    while not msg:
        data_p = sk.recv(1024)
        if not data_p:
            raise ConnectionError()
        data = data + data_p
        #Nếu có null
        if b'\0' in data_p:
            msg = data.rstrip(b'\0')
    msg = msg.decode('utf-8')
    return msg

# Tạo message (Thêm kí tự null vào message)
def create_msg(msg):
    msg = msg + '\0'
    return msg.encode('utf-8')
def send_msg(sk, msg):
    data = create_msg(msg)
    sk.sendall(data)