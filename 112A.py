import sys
import functools
import string

input = sys.stdin.readline
print = sys.stdout.write

string_1 = str(input()).lower()
string_2 = str(input()).lower()

if string_1 > string_2:
	print(str(1))
elif string_1 < string_2:
	print(str(-1))
else:
	print(str(0))