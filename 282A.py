import sys

input = sys.stdin.readline
print = sys.stdout.write

lim = int(input())
res = 0

for i in range(lim):
	statement = str(input())
	if '++' in statement:
		res += 1
	elif '--' in statement:
		res -= 1

print(str(res))