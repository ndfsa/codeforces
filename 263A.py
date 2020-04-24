import sys

input = sys.stdin.readline
print = sys.stdout.write

mat = [list(map(int, input().split())) for _ in range(5)]

for i in range(5):
	if 1 in mat[i]:
		col = mat[i].index(1)
		print(str(abs(i - 2) + abs(col - 2)))