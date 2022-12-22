host = "127.0.0.1"
port = 9050
import socket

if __name__ == "__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    while True:
        data, addr = sk.recvfrom(1024)
        input_data = data.decode('utf-8')
        print("Client gui: " + input_data)
        if input_data == "q":
            break
        count = 0
        for x in input_data:
            if x.isupper():
                count += 1
        data = str(count)
        # msg = input("Sever: ")
        sk.sendto(data.encode('utf-8'), addr)
