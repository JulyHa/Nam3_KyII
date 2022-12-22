# import Buoi11_BaseModule
# import threading
# host = Buoi11_BaseModule.host
# port = Buoi11_BaseModule.port
#
# def xuly_client(sk, addr):
#     try:
#         msg = Buoi11_BaseModule.recv_msg(sk)
#         print("{}:{}".format(addr, msg));
#         Buoi11_BaseModule.send_msg(sk,msg)
#     except (ConnectionError, BrokenPipeError):
#         print("Error")
#     finally:
#         sk.close();
#
# if __name__ == '__main__':
#     sk = Buoi11_BaseModule.create_socket(host, port)
#     addr = sk.getsockname();
#     print("Listen on : {}".format(addr));
#
#     # while True:
#     #     client_sk, addr = sk.accept()
#     #     print("Connection from {}".format(addr))
#     #     xuly_client(client_sk, addr)
#
#     while True:
#         client_sk, addr = sk.accept()
#         thread = threading.Thread(target=xuly_client, args = [client_sk, addr], daemon= True)
#         thread.start()
#         print("Connection from {}".format(addr))



import  socket
host = '127.0.0.1'
port = 9050

if __name__ == '__main__':
    sk = sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    while True:
        # server nhận từ client
        data, addr = sk.recvfrom(1024)
        print(data.decode('utf-8'))

        sk.sendto(data, addr)