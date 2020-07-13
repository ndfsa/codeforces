lucky = [4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777]

n = int(input())
flag = False

for l in lucky:
	if l > n:
		break
	elif n % l == 0:
		flag = True
		break

if (flag):
	print('YES')
else:
	print('NO')