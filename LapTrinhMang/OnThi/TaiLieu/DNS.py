# -*- coding: utf-8 -*-
"""
Created on Sat Jun  4 11:21:22 2022

@author: dangq
"""

import dns.resolver

if __name__=='__main__':
    url='python.org'
    ip=dns.resolver.resolve(url,'A')
    print("hostname: ",url)
    for i in ip:
        print('IP ',i.to_text())
    # name=dns.reversename.from_address('138.197.63.241')
    # print(name)
    # print(dns.reversename.to_address(name))