import sys

input = sys.stdin.readline
print = sys.stdout.write

n = int(input())

print('YES' if n != 2 and n >= 0 else 'NO')