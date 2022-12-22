import  ftplib
from ftplib import FTP

def test_ftp(host, username):
    #ketnoi
    ftp = ftplib.FTP(host, username)
    #chuyen thu muc
    # ftp.cwd('/pub/linux/network/wireless/')
    #lien ket thu muc
    # f = ftp.dir()
    # print(f)
    fname = 'Hello_Juu.txt'
    f_handle = open(fname, 'wb')
    ftp_cmd = 'RETR %s'%fname
    #bat dau downlode file
    ftp.retrbinary(ftp_cmd, f_handle.write)
    f_handle.close()
    ftp.quit()

if __name__ == '__main__':
    #test_ftp('127.0.0.1', 'Ngu')
    s = "Hello  i am , a student . i am from  vietnam"
    res = s[0]
    for i in range(1, len(s)):
        if s[i-1] == '.'and s[i] >= 'a':
            res+=chr(ord(s[i])-32)
        else:
            res += s[i]
    print(res)
