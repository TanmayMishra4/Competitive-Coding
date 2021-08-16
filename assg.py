import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl
import re
# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')

count = int(input("enter counts  "))
pos = int(input("enter position  "))
pos = pos - 1

lst = list()
# Retrieve all of the anchor tags
for times in range(count):
    html = urllib.request.urlopen(url, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')
    tags = soup('a')
    lst.append(tags[pos].get('href',None))
    url = tags[pos].get('href',None)

ans = re.findall('known_by_([a-zA-Z]+)',lst[count-1])
print(ans[0])
