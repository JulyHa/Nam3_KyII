# Lấy header của 1 url có sẵn
#import urllib.request as ur
#from urllib.request import urlopen
#import gzip
#import urllib.error


# if __name__ == '__main__':
#     try:
#         #tạo đối tượng request sau đó thêm header vào
#         req = ur.Request('http://www.facebook.com')
#         req.add_header('Accept-Encoding', 'gzip')
#         response = urlopen(req)
#         text = gzip.decompress(response.read())
#
#         print(text) #In ra header
#
#         # print(response.url)
#         # print(response.readline())
#         # print(response.read()) #đọc file html
#         # print(response.getheaders())
#     except urllib.error.HTTPError as err:
#         print('status: ', err.code)
#         print('url: ', err.url)
import gzip
import urllib.error
import urllib.request

if __name__ == '__main__':
    try:
        req = urllib.request.Request('http://www.vnexpress.net')
        req.add_header('Accept-Encoding', 'gzip')
        res = urllib.request.urlopen(req)

        header = res.getheaders()
        print(header)
        text = gzip.decompress(res.read())  # lấy body
        # print(text)
    except urllib.error.HTTPError as err:
        print(err.code)
