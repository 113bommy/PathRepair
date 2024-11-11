from collections import Counter as c
for _ in range(int(input())):
	a,b = map(int,input().split())
	st = input()
	s = c(st)
	t = sorted(s.keys())
	ans =""
	if s[t[0]]<b:
		print(sorted(st)[b-1])
	elif b==1:
		print("".join(sorted(st)))
	elif s[t[0]]==a:
		from math import ceil
		print(t[0]*ceil(a/b))
	else:
		s[t[0]]-=b
		ans+=t[0]
		# print(s)
		if s[t[0]]:
			for i in t:
				ans+="i"*s[i]
		else:
			if len(t)==2:
				from math import ceil
				ans+=t[1]*ceil(s[t[1]]/b)
			else:
				for i in t:
					ans+=i*s[i]
			print(ans)
