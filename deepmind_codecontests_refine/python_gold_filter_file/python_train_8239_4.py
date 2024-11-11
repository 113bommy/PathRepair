n = int(input())
m= list(map(int,input().split()))
r=0
d=m[0]
for i in m:r+=i
r//=2
gd=["1"]

for x in range(1,n):
	if m[0]>=(m[x]*2):
		d+=m[x]
		gd.append(str(x+1))


if d>r:
	print(len(gd))
	print(' '.join(gd))
else:
	print(0)