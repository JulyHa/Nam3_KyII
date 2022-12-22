import socket

if __name__ == "__main__":
    hostname = socket.gethostname()
    print(hostname)
    IpAdr = socket.gethostbyname(hostname)
    print("Dia chi IP: " + IpAdr)
    IpAdr_VN = socket.gethostbyname('facebook.com')
    print("Dia chi IP cua facebook: " + IpAdr_VN)
