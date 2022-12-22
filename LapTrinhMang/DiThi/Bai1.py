import urllib.request

if __name__ == '__main__':
    try:
        req = urllib.request.Request('https://localhost:44355/Home/Index')
        req.add_header("Accept-Encoding", "gzip")
        res = urllib.request.urlopen(req)

        header = res.getheaders()
        print(header)
    except urllib.error.HTTPError as err:
        print(err.code)
