n=int(input())
dig=[]
dec=0
z=0
for _ in range(n):
	x=float(input())
	dec+=round(x-int(x),5)
	dig.append([int(x),round(x-int(x),5)])
c=round(dec)
f=-1 if c>0 else 1

for i in range(n):
	if c*(dig[i][0]+dig[i][1])>0 and c!=0 and dig[i][1]!=0:
		dig[i][0]+=-f
		c+=f
print(*[dig[i][0] for i in range(n)])
