from urllib.request import urlopen
from urllib.request import Request
import socket
import gzip
import urllib.error

if __name__ == '__main__':

    try:
    #tạo đối tượng request sau đó thêm header vào
        req = Request("http://www.vnexpress.net")
        req.add_header('Accept-Encoding', 'gzip')
        response = urlopen(req)
        #response = urlopen("http://www.vnexpress.net")
        #print(response.url)
        #print(response.status)
        #print(response.readline())
        #print(response.read()) #đọc file html
        print(response.getheaders())
        # text = gzip.decompress(response.read())
        # print(text)
    except urllib.error.HTTPError as err:
        print('status', err.code)
        print('url',err.url)

