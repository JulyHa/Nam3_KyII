import pip
import requests.utils
import urllib.request
from bs4 import BeautifulSoup
import requests
# if __name__ == '__main__':
#     url = 'https://forecast.weather.gov/MapClick.php?lat=37.7772&lon=-122.4168'
#     headers = requests.utils.default_headers()
#     r = requests.get(url,headers)
#     bs = BeautifulSoup(r.content,'html.parser')
#     ngay = bs.find(id='seven-day-forecast')
#     dubao = ngay.find_all(class_='tombstone-container')
#     tonight = dubao[0]
#     img = tonight.find("img")
#     mota = img['title']
#     print(mota)
#
#     list = [1,2,3,4,5,6,7]
#     for i in list:
#         tonight = dubao[i]
#         period = tonight.find(class_='period-name').get_text()
#         short_desc = tonight.find(class_='short-desc').get_text()
#         temp = tonight.find(class_='temp').get_text()
#         print(period, short_desc, temp)
import ipaddress as ip
# if __name__ == '__main__':
#     ipaddr = ip.ip_network('10.0.1.0/24')
#     print(ipaddr.netmask)
#     print(str(ipaddr.netmask))
#     print(str(ipaddr.network_address))
#     print(str(ipaddr.num_addresses))
#     host = list(ipaddr.hosts())
#     print(host)
#     subnet = list(ipaddr.subnets())
#     print(subnet)
#
# if __name__ == '__main__':
#     ip_addr = '192.168.0.0'
#     s = input("nhap prefix: ") #26
#     ip_net = ip_addr + '/' + s #192.168.0.0/26
#     print("Dia chi mang: ", ip_net)
#     network = ip.ip_network(ip_net)
#     print("\tHost number: %s"%str(network.num_addresses))
#     print("\tSubnet mask: %s"%str(network.netmask))
#     print("\tProascast: %s"%str(network.broadcast_address))
#     ip_dau, ip_cuoi = list(network.hosts())[0],list(network.hosts())[-1]
#     print("\tDia chi IP tu %s den %s "%(ip_dau, ip_cuoi))
# from geoip import geolite2
import socket
# if __name__ == '__main__':
#     hostname = socket.gethostname()
#     ip_addr = socket.gethostbyname(hostname)
#     tt = geolite2.lookup(ip_addr)
#     print("Country: ", tt.country)
#     print("Timezone: ", tt.timezone)

import json
from urllib.request import urlopen
# if __name__ == '__main__':
#     url = 'http://ipinfo.io/json'
#     r = urlopen(url)
#     data = json.load(r)
#     ipaddr = data['ip']
#     org = data['org']
#     country = data['country']
#     city = data['city']
#     region = data['region']
#     print(ipaddr, org, country, city, region)

# if __name__ == '__main__':
#     url = 'https://geolocation-db.com/jsonp'
#     r = requests.get(url)
#     data = r.content.decode()
#     data = data.split("(")[1].strip(")")
#     data = json.loads(data)
#     print(data)
#
#pip install dnspython
import dns.resolver
if __name__ == '__main__':
    ip = dns.resolver.resolve('python.org','A')
    for i in ip:
        print("IP: ", i.to_text())

