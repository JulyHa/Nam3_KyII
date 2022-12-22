import paramiko

def test_ssh(host,port, user, password, command):
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    #connect den sever/ remove computer
    ssh.connect(host,port, user, password)
    #chuyền file
    f = ssh.open_sftp()
    sourcefile = 'D:/Uyen/Tonghop/TrenLop_Class/Nam3/Ky_II/LapTrinhMang/Code/test.txt'
    remotefile = '/C/ProgramData/test.txt'
    f.put(sourcefile, remotefile)
    f.close()
    #Đẩy nhiều file lên
    list = ['file1.txt, file2.txt, fil3.txt']
    for i in list:
        f = ssh.open_sftp()
        sourcefile = 'D:/Uyen/Tonghop/TrenLop_Class/Nam3/Ky_II/LapTrinhMang/Code/'+i
        remotefile = '/C/ProgramData/'+i
        f.put(sourcefile, remotefile)
        f.close()
    #download file
    # f = ssh.open_sftp()
    # sourcefile = 'abc.txt'
    # remotefile = '/C/ProgramData/abc.txt'
    # f.get(remotefile,sourcefile )
    # f.close()

    #thực hiện lệnh
    stdin,stdout, stderr = ssh.exec_command(command)
    #output = stdout.readlines()
    output = stdout.read().decode()
    print(output)

if __name__ == '__main__':
    test_ssh('127.0.0.1', 22, 'nguyenngu', '123', 'ls')