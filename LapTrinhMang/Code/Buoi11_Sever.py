import Buoi11_BaseModule

host = Buoi11_BaseModule.host
port = Buoi11_BaseModule.port


def client_process(sk, addr):
    try:
        # Nhân message
        msg = Buoi11_BaseModule.recv_msg(sk)
        if msg == 'q':
            sk.close()
            return
        print("{}:{}".format(addr, msg))
        Buoi11_BaseModule.send_msg(sk, msg)
    except (ConnectionError, BrokenPipeError):
        print("Socket error")
    finally:
        sk.close()


if __name__ == '__main__':
    sk = Buoi11_BaseModule.create_socket(host, port)
    addr = sk.getsockname()
    print("Listent on local port {}".format(addr))
    while True:
        client_sk, addr = sk.accept()
        print("Connection from {}".format(addr))
        client_process(client_sk, addr)
