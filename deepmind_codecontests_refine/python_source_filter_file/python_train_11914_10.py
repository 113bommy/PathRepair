
a,b,c=map(int,input().split())
j=list(map(int,input().split()))
k=list(map(int,input().split()))
p=[]
if min(b,c)==b:
	for x in range(b):
		if j[x] in k:
			p.append(j[x])
			k.remove(j[x])
		else:
			p.append(j[x])
else:
	for x in range(c):
		if k[x] in j:
			p.append(k[x])
			j.remove(k[x])
		else:
			p.append(k[x])
for x in range(a):
	if min(b,c)==c:
		if x+1 in p:
			print(1,end=' ')
		else:
			print(2,end=' ')
	else:
		if x+1 in p:
			print(2,end=' ')
		else:
			print(1,end=' ')