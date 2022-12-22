# Dir (lấy tất cả các thư mục)
import ftplib

def get_dir(host, username):
    ftp = ftplib.FTP(host, username)
    # ftp.connect(host, port)
    # ftp.login(username)
    # print(ftp.getwelcome())
    # f = ftp.dir() #Lấy thông tin các file
    # ftp.cwd('/new1') #chuyển vào thư mục bên trong
    f = ftp.nlst()  # Liệt kê tên file
    print(f)
    ftp.quit()


if __name__ == '__main__':
    # get_dir(host='127.0.0.1', username='Ngu', port=20)
    get_dir(host='127.0.0.1', username='Ngu')