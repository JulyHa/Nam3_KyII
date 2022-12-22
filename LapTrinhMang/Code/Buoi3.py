import urllib.request
import urllib.request as ur
from http.cookiejar import CookieJar
from urllib.request import build_opener, HTTPCookieProcessor
import datetime
import requests
# if __name__ == '__main__':
#     req = ur.Request('http://www.facebook.com')
#     res = ur.urlopen(req)
#     print(res)
#     print(req.get_header('User-agent'))

#Cookie

if __name__ == '__main__':
    cookie_jar = CookieJar()
    opener = build_opener(HTTPCookieProcessor(cookie_jar))
    kq = opener.open('http://www.facebook.com')
    print(kq)
    print(len(cookie_jar))
    cookie = list(cookie_jar)
    print(cookie)
    print(cookie[0].domain)
    print(cookie[0].path)
    print(cookie[0].expires) #thời gian sống của 1 cookie

    time = datetime.datetime.fromtimestamp(cookie[0].expires) #đổi về datetime
    print(time)

    #kiểm tra xem cờ http only có được khởi động không
    print(cookie[0].get_nonstandard_attr('HttpOnly'))
    print(cookie[0].secure)
# if __name__ == '__main__':
#     r = requests.get("http://httpbin.org/get")
#     print("Status code"+str(r.status_code))
#     print(r.headers)
#     print("In dang key-value")
#     if r.status_code == 200:
#         r1 = r.json()
#         for i in r1.items():
#             print(i)
#         print("Header reponse")
#         for header, value in r.headers.items():
#             print(header, '-->', value)
#         print("Header request")
#         for header, value in r.request.headers.items():
#             print(header, '-->', value)
#         print("server: "+r.headers['server'])
#     else:
#         print("Ma loi: %s"%r.status_code)


import re
# if __name__ == '__main__':
#     user_agent = 'Mozilla/5.0 (Linux; Android 10) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.101 Mobile Safari/537.36'
#     url = 'https://mmgroup.vn/tao-email-ten-mien-voi-google/'
#     opener = urllib.request.build_opener()
#     opener.addheaders = [('User-agent', user_agent)]
#     urllib.request.install_opener(opener)
#     r = urllib.request.urlopen(url)
#     data = r.read()
#     mau_email = re.compile("[-a-zA-Z0-9._]+[-a-zA-Z0-9._]+@[-a-zA-Z0-9_]+.[a-zA-Z0-9_.]+")
#     email = re.findall(mau_email, str(data))
#     print(email)

# if __name__ == '__main__':
    # user_agent = 'Mozilla/5.0 (Linux; Android 10) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.101 Mobile Safari/537.36'
    # url = 'https://mmgroup.vn/tao-email-ten-mien-voi-google/'
    # r = requests.get(url, timeout=5).text
    # print("Image")
    # for i in re.findall("<img (.*)>", r):
    #     for j in i.split():
    #         if re.findall("src=(.*)", j):
    #             i = j[:-1].replace("scr=\"", "")
    #         if i.startswith("http"):
    #             print(i)
    #         else:print(url+i)

    # print("Link")
    # for link, name in re.findall("<a(.*)>(.*)</a>", r):
    #     for a in link.split():
    #         if re.findall("href=(.*)", a):
    #             url_link = a[0:-1].replace("href=\"", "")
    #         if (url_link.startswith("http")):
    #             print(url_link)
    #         else:
    #             print(url + url_link)