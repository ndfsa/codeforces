import functools

lst = list(input().split('+'))

lst.sort()

res = functools.reduce(lambda acc, item: acc + '+' + item, lst)

print(res)