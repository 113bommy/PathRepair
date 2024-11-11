n=int(input())
a=[int(input()) for i in range(n-1)]
d={i:set() for i in set(a)}
for i in range(n-1):
	d[a[i]].add(i+2)
f=0
for i in d:
	w=(d[i]-(set(d.keys())-{i}))
	if 	len(w)<3:
		f=1
		break
if f==1:
	print("No")
else:
	print("Yes")
