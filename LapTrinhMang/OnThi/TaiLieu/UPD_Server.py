
host = "127.0.0.1"
port = 9050
import socket 
if __name__=="__main__":
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sk.bind((host, port))
    while True:
        data, addr = sk.recvfrom(1024)        
        print("Client gui: " + data.decode('utf-8'))
        if(data.decode('utf-8') == "q"):
            break 
        msg = input("Sever: ")
        sk.sendto(msg.encode('utf-8'), addr)
        