import  ftplib
from ftplib import FTP
def Test(host, user):
    #ketnoi
    ftp = ftplib.FTP(host, user)
    #liet ke thu muc
    f = ftp.dir()
    files = ftp.nlst()

    print(files)

if __name__ == '__main__':
    Test(host='127.0.0.1', user='Ngu')

# import paramiko
# if __name__ == '__main__':
#     host = '127.0.0.1'
#     user = 'Ngu'
#
#     #ket noi den server
#     ssh = paramiko.SSHClient()
#     #ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
#     ssh.connect(host, port=2222, username=user)
#
#     #lenh liet ke cac thu muc
#     stdin, stdout, stderr = ssh.exec_command('ls')#trả về 3 giá trị
#     print(stdin)