# https://codeforces.com/problemset/problem/1146/B

import string

t = input()

if t == 'a'*len(t):
	print(t)
else:
	last = t[len(t)-1]
	list_letters = [x for x in t if x != 'a']
	print(list_letters)
	length = int(len(list_letters)/2)
	if len(list_letters) % 2 != 0:								# case where letters different from 'a' in t are odd
		print(':(')
	else:
		suffix = ''.join(list_letters[:length])
		print(suffix)
		if t.endswith(suffix) and suffix != '':
			print(t[:-len(suffix)])
		else:
			print(':(')
