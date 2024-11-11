n=int(input())
l=list(map(int,input().split()))
l.sort()
s=c=0
for i in l:
	if s>i:
		pass
	else:
		c+=1
		s+=i
print(c)