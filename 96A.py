import re

string = str(input())

if (re.search('0{7}|1{7}', string)):
	print('YES')
else:
	print('NO')