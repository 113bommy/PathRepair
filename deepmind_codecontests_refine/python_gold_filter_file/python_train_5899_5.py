from collections import Counter

a = input()
cnt = Counter(a)
if a != ''.join(sorted(a)):
	print('NO')
elif 'ab' not in a or 'bc' not in a:
	print('NO')
elif cnt['a'] != cnt['c'] !=  cnt['b']:
	print('NO')
else:
	print('YES')
