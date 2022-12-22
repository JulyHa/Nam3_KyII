import dns.resolver
import netifaces  # pip install netifaces
if __name__=='__main__':
    url='python.org'
    ip=dns.resolver.resolve(url,'A')
    print("hostname: ",url)
    for i in ip:
        print('IP ',i.to_text())
    name = dns.reversename.from_address('138.197.63.241')
    print(name)
    print(dns.reversename.to_address(name))