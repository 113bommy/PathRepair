s = input()
l,r = s.find('['), s.rfind(']')
if l == -1 or r == -1: print(-1)
else:
	news = s[l:r+1]
	l2,r2 = news.find(':'),news.rfind(':')
	if l2 == r2: print(-1)
	else:
		v = news[l2:r2+1].count("|")
		print(v+4)