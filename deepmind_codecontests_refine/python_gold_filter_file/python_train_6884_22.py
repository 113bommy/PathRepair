s = input()
try:
	b = s.index('[')
	e = s.rindex(']')
	cb = s[b:e].index(':')
	ce = s[b:e].rindex(':')
	if b>e or cb==ce:
		raise ValueError
	res = 4 + s[b+cb:b+ce].count('|')
	print(res)
except ValueError:
	print(-1)