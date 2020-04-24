lim = int(input())
string = str(input())
cont = 0

for i in range(1, lim):
	if (string[i - 1] == string[i]):
		cont += 1

print(cont)	