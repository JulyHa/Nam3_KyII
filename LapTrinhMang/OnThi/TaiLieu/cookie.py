# -*- coding: utf-8 -*-
"""
Created on Sat Jun  4 10:54:18 2022

@author: dangq
"""

from http import cookiejar
from http.cookiejar import Cookie, CookieJar
from urllib.request import build_opener, HTTPCookieProcessor


if __name__=='__main__': 
    #tao khong gian de luu cookie
    cj= CookieJar()
    #tao urllib builder -> tu dong lay ra cookie tu response cua server
    opener= build_opener(HTTPCookieProcessor(cj))
    #tao http request 
    v=opener.open('http://www.github.com')
    #print(v)
    #print(len(cj))
    #CookieJar khong cho phep truy cap truc tiep -> tao list de lay tung cookie
    Cookies=list(cj)
    print(Cookies)
    #print(Cookies[1].name)
    #print(Cookies[1].value)
    #print(Cookies[1].domain)
    #print(Cookies[1].path)
    #print(datetime.datetime.fromtimestamp(Cookies[1].expires)) #unixtime
    #print(Cookies[0].secure)