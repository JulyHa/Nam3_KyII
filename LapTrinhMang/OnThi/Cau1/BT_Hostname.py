# Lấy host name và IP của máy
# Lấy host name của
import socket

if __name__ == "__main__":
    hostname =socket.gethostname()
    print("Host name = ", hostname)
    IP = socket.gethostbyname(hostname)
    print("IP = ", IP)
    IP_fb = socket.gethostbyname('facebook.com')
    print("IP facebook = ", IP_fb)
