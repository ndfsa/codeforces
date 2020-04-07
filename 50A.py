import sys

input = sys.stdin.readline
print = sys.stdout.write

m, n = tuple(map(int, input().split()))

print(str(m * n // 2))