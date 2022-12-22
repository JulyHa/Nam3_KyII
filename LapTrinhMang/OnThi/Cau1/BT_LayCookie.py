#Cookie
from http.cookiejar import CookieJar
from urllib.request import build_opener, HTTPCookieProcessor
import datetime

if __name__ == '__main__':
    cookie_jar = CookieJar()
    opener = build_opener(HTTPCookieProcessor(cookie_jar))
    kq = opener.open('http://www.facebook.com')
    # print(kq)
    # print('Độ dài của cookie: ', len(cookie_jar))
    cookie = list(cookie_jar)
    print(cookie)
    # print('Domain: ', cookie[0].domain)
    # print('Path: ', cookie[0].path)
    # print('Thời gian sống của 1 cookie: ', cookie[0].expires) #thời gian sống của 1 cookie
    #
    # time = datetime.datetime.fromtimestamp(cookie[0].expires) #đổi về datetime
    # print('Thời gian sống đổi về date time: ', time)
    #
    # print(cookie[0].get_nonstandard_attr('HttpOnly'))  #kiểm tra xem cờ http only có được khởi động không
    # print(cookie[0].secure) #bảo mật hay ko