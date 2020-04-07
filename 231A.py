import sys

input = sys.stdin.readline
print = sys.stdout.write

num_problems = int(input())
res = 0

for i in range(num_problems):
	problem = list(map(int, input().split()))
	if (sum(problem) > 1):
		res += 1

print(str(res))