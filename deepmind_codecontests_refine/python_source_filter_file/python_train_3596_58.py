n,count = map(int,input().split())
s = []
e = 0
for i in range(n):
	r,f = map(str,input().split())
	if r == "+":
		s.append(int(f))
	else:
		s.append(-1*int(f))

for i in range(n):
	if s[i]>=0:
		count+=s[i]
	else:
		if s[i]+count > 0:
			count+= s[i]
		else:
			e+=1
			pass


print(count,e)

