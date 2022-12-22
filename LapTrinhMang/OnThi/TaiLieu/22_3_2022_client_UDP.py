# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 14:21:57 2022

@author: dangq
"""

import socket
host='127.0.0.1'
port=5050

if __name__=='__main__':
    sk=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    msg="hello server"
    while True:
        msg=input("nhap message q de thoat")
        sk.sendto(msg.encode('utf-8'),(host,port))
        #nhan tu server
        data,addr=sk.recvfrom(1024)
        print("server gui lai "+data.decode("utf-8"))
        
        
    
    