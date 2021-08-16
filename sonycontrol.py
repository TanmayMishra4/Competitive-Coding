import concurrent.futures
from bravia_tv import BraviaRC
import sys

def contact(ip_address):
	braviarc = BraviaRC(ip_address)

	pin = '0000'
	try:
		a = braviarc.connect(pin, '73:16:9e', 'SONY KD-65A8H')
	except Exception as e:
		return
	else:
		if a:
			print('---------------success---------------')
			print(ip_address)
			

a = '192.168.1.'
ip_address_list = [a+str(i) for i in range(50)]

with concurrent.futures.ThreadPoolExecutor() as executor:
	executor.map(contact, ip_address_list)


# for ip_add in ip_address_list:
# 	contact(ip_add)

