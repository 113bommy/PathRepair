#!/usr/bin/python3.4
a="AHIMOTUVWXYmovwx"
b={'b':'d', 'd':'b', 'p':'q', 'q':'p'}
s=str(input())

ok = True
slen = len(s)
for i in range((slen - 1) // 2 + 1):
	if (s[i] in a and s[i] == s[slen - i - 1]) or (b.get(s[i], 0) and b[s[i]] == s[slen - 1 - i]):
		continue
	else:
		ok = False
		break;
print(['NIE', 'TAK'][ok])

