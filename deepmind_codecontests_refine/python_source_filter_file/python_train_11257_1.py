x=[int(s) for s in input().split()]
y=x[1]
s=input()
r=[]
c=1
m=0
d="_"
for i in s:
	if i==d:
		c+=1
	elif d=="_":
		d=i
	else:
		r.append((c,d))
		c=1
		d=i
r.append((c,d))
for i in "abcdefghijklmnopqrstuvwxyz":
	tm=0
	for f,l in r:
		if f>=y and i==l:
			tm+=1
	m=max(m,tm)

print(m)