t = int(input())
while t>0:
	s = input()
	a = dict()
	b = dict()
	for i in range(len(s)):
		if s.count(s[i])%2==0:
			a[s[i]] = s.count(s[i])
	for k,v in a.items():
		c = 0
		o = 0
		while o<len(s)-1:
			if s[o] == k and  s[o] == s[o+1]:
				c+=1
				o+=2
			else:
				o+=1
		if c==v/2:
			b[k] = v
	re = []
	key = list(b.keys())
	for i in range(len(s)):
		if key.count(s[i])==0 and re.count(s[i])==0:
			re.append(s[i])
	re.sort()
	res = ''
	for i in range(len(re)):
		res+=re[i]
	print(res,'\n')
	t-=1