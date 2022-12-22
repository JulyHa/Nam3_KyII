# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 14:12:24 2022

@author: dangq
"""

import socket
host='127.0.0.1'
port=9051

if __name__=='__main__':
    sk=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sk.bind((host,port))
    while True:
        #server nhan
        data,addr=sk.recvfrom(1024)
        #gui lai
        print("client gui"+data.decode('utf-8'))
        msg="server gui lai"
        sk.sendto(msg.encode('utf-8'),addr)
        if(data.decode('utf-8'))=='q':
            break
        
    