n,k=map(int,input().split())
s=input()
l=set(s)
if len(l)!=k:
	print(0)
else:	
	a=[]
	for i in l:
		a.append(s.count(i))
	print(min(a)*3)