m, n = map(int, input().split())
s = input()
t = input()
if s.find('*')!=-1:
	ls, rs = s.split('*')
	if len(ls) == 0:
		if len(rs) == 0:
			print("YES")
		elif t.find(rs)+len(rs) == len(t):
			print("YES")
		else:
			print("NO")
	elif ls[0] == t[0]:
		if t.find(ls) != -1:
			d = t.find(ls)
			if t[d+len(ls):].find(rs) != -1:
				if t[d+len(ls):].find(rs)+len(rs) == len(t[d+len(ls):]):
					print("YES")
				else:
					print("NO")
			else:
				print("NO")
		else:
			print("NO")
	else:
		print("NO")
else:
	if s==t:
		print("YES")
	else:
		print("NO")