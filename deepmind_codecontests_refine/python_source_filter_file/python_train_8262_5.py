I=input
I()
a={}
for x in map(int,I().split()):
	if x:a[x]=a.get(x,0)+1
a=list(a.values())
b=max(a+[0])
print([-1,list(a).count(2)][b in(0,2)])