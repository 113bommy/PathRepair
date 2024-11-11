d={}
n=input()
s=input()
v=input()
l=[]
for i in range(len(n)):
	d[n[i]]=s[i]
for i in v.lower():
	if i.isalpha():
		l.append(d[i])
	else:
		l.append(i)
for i in range(len(l)):
	if v[i].isupper():
		l[i]=chr(ord(l[i])-32)
print(*l)