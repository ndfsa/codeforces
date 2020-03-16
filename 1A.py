import sys
import math

input = sys.stdin.readline
print = sys.stdout.write

lst = list(map(float, input().split()))

a = math.ceil(lst[0]/lst[2])
b = math.ceil(lst[1]/lst[2])

print(str(a * b))