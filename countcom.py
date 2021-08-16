import urllib.request, urllib.error, urllib.parse
import ssl
import xml.etree.ElementTree as ET

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input("enter url ")
data = urllib.request.urlopen(url,context = ctx).read()

tree = ET.fromstring(data)
total = 0
for r in tree.findall('.//count'):
    total += int(r.text)
print(total)
