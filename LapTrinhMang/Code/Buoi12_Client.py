# import socket
# import Buoi11_BaseModule
#
# host = Buoi11_BaseModule.host
# port = Buoi11_BaseModule.port
#
# if __name__ == '__main__':
#     while True:
#         try:
#             sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#             sk.connect((host, port))
#             print("Enter message (q to exit:) ")
#             msg = input()
#             if msg == 'q':
#                 break
#             Buoi11_BaseModule.send_msg(sk,msg)
#             print("Send: {}".format(msg))
#
#             #Nhận về
#             msg = Buoi11_BaseModule.recv_msg(sk)
#             print("Receive: " + msg)
#         except ConnectionError:
#             print("Socket error")
#             break
#         finally:
#             sk.close()


import  socket
host = '127.0.0.1'
port = 9050

if __name__ == '__main__':
    sk = sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    #client gửi msg
    msg = "Hello server"
    sk.sendto(msg.encode('utf-8'), (host, port))

    #nhận lại từ sever
    data, addr = sk.recvfrom(1024)
    print("Sever gửi: " + data.decode('utf-8'))