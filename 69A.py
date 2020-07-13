lim = int(input())
sum_ = [0, 0, 0]
for i in range(lim):
	v = tuple(input().split())
	sum_[0] += int(v[0])
	sum_[1] += int(v[1])
	sum_[2] += int(v[2])

if sum_ == [0, 0, 0]:
	print('YES')
else:
	print('NO')