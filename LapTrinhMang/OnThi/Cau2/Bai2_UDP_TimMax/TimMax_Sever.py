host = "127.0.0.1"
port = 9050
import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    while True:
        data, addr = sk.recvfrom(1024)
        input_data =  data.decode('utf-8')
        print("Client gui: " + input_data)
        if input_data == "q":
            break
        a,b = map(int, input_data.split(' '))
        res = max(a, b)
        data = str(res)
        # msg = input("Sever: ")
        sk.sendto(data.encode('utf-8'), addr)
