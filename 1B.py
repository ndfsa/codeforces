import re
import functools

lim = int(input())

def to_letter_base(n):
	res = str()
	while(n > 0):
		residue = n % 26
		n = n // 26
		if residue == 0:
			res = 'Z' + res
			if n == 1:
				return res
			else:
				n = n - 1
		else:
			res = chr(residue + 64) + res
	return res


for case in range(lim):
	cell = str(input())
	m = re.match('\\b(?P<col>[A-Z]+)(?P<row>[0-9]+)\\b', cell)
	if m:
		col = functools.reduce(lambda acc, item: ord(item) - 64 + acc * 26, m.group('col'), 0)
		print('R', m.group('row'), 'C', col, sep='')
	else:
		tokens = cell[1:].split('C')
		col = ''.join(to_letter_base(int(tokens[1])))
		print(col, tokens[0], sep='')