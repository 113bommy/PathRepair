a=input().strip()
n=int(input())
k=[input() for i in range(n)]
p=[]
for i in k:
	if a in i and i.index(a)==0:
		p.append(i)
if p:
	print(min(k))
else:
	print(a)
