import sys
import functools

input = sys.stdin.readline
print = sys.stdout.write

vowels = 'aeiouy'
_in = filter(lambda x: x != '\n', str(input()).lower())

res = functools.reduce(lambda acc, item: acc + '.' + item, filter(lambda x: x not in vowels, _in), '')
print(res)