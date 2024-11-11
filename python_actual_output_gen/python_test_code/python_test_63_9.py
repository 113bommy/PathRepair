n=int(input())
l=list(map(int,input().split()))
a1=l.count(1)
a2=l.count(2)
a3=l.count(3)
v=[]
v.append(a1)
v.append(a2)
v.append(a3)
l=set(v)
v=list(l)
a=max(a1,a2,a3)
if len(v)==1:
	print('0')
else:
	v.remove(a)
	print(sum(v))