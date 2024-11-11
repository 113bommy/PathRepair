n=int(input())
l=list(map(int,input().split()))
c=0
t=0
for i in range(n):
	if l[i]==i:
		c+=1
	elif l[i]!=i and l[l[i]]==l[i]:
		t+=1
	else:
		pass
if c!=n:
	if t>0:
		print(c+2)
	else:
		print(c+1)
else:
	print(c)