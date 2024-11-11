# http://codeforces.com/problemset/problem/716/B

from collections import Counter
import string

def can_complete(s):
	if len(s) < 26:
		return False, -1
	count = Counter()
	for x in string.ascii_uppercase:
		count[x] = 0
	can = 0
	first = s[0]
	i, j = 0, 26
	for k in range(i, j):
		if s[k] != '?':
			count[s[k]] += 1
			if count[s[k]] == 1:
				can += 1
		else:
			can += 1
	if can == 26:
		return count, i
	i += 1
	j += 1
	while j < len(s):
		if first != '?':
			count[first] -= 1
			if count[first] == 0:
				can -= 1
		else:
			can -= 1

		if s[j] != '?':
			count[s[j]] += 1
			if count[s[j]] == 1:
				can += 1
		else:
			can += 1

		if can == 26:
			return count, i
		first = s[i]
		i += 1
		j += 1
	return False, -1

s = input()
res, i = can_complete(s)
if not res:
	print(-1)
else:
	can_use = [k for k in res if res[k] == 0]
	q = 0
	for h in range(len(s)):
		x = s[h]
		if x == '?':
			if i <= h < i + 26:
				x = can_use[q]
				q += 1
			else:
				x = 'A'
		print(x, end='')
	print()
