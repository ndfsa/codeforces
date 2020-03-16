import sys

input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
string = []
for i in range(n):
	string.append(str(input()))
	
for s in string:
	if len(s) > 11:
		print(s[0] + str(len(s[1:-2])) + s[-2] + '\n')
	else:
		print(s)