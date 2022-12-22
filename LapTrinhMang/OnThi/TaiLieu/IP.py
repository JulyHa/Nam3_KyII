# -*- coding: utf-8 -*-
"""
Created on Sat Jun  4 11:32:46 2022

@author: dangq
"""

# from geoip import geolite2
import ipaddress as ip
if __name__=='__main__':
    ip_addr='192.168.0.0'
    s=input("nhap prefix (so bit):")#26
    net_addr=ip_addr+'/'+s    #192.168.0.0/26
    print("dia chi mang: %s" %net_addr)
    network=ip.ip_network(net_addr)
    print("so luong host: %s" %(network.num_addresses))
    print("\t dia chi mang: %s" %str(network.network_address))
    print("\t subnetmark: %s" %str(network.netmask))
    print("\t dia chi broadcast: %s" %str(network.broadcast_address))
    dcdau=list(network.hosts())[0]
    dccuoi=list(network.hosts())[-1]
    print("\t dia chi ip cua cac may tu %s den %s" %(dcdau,dccuoi))