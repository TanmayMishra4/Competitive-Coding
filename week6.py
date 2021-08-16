import urllib.error, urllib.parse, urllib.request
import ssl
import json

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input("Enter URL")
connection = urllib.request.urlopen(url,context=ctx).read()
info = json.loads(connection.decode())
s = 0
for p in info['comments']:
	s = s + p['count']
print(s)