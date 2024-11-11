s=list(input())
k=set()
r=0
for i in range(len(s)):
	if(s[i]=='?'):
		r=r+1
	elif(ord(s[i])>64):
		k.add(s[i])
r=10**r
m=10
for i in range(len(k)):
	r=r*m
	m=m-1
if(ord(s[0])>=57):
	r=(r//10)*9
print(r)