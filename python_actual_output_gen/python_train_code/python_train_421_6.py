n = int(input())
a = list(map(int,input().split()))
z,v=0,[]
for i in range(n-1):
	if a[i]>a[i+1]:v.append(a[i]);z=1
	elif z==1:break
if len(v)==0:print("yes");print(a[0],a[0])
else:
	q = a.index(v[0])
	w = a.index(v[-1])
	v.append(a[w+1])
	t = a[:q]+v[::-1]+a[w+2:]
	a.sort()
	if t == a:print("yes");print(q+1,w+2)
	else:print("no")