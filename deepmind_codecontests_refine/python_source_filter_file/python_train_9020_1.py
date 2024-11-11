import sys
input=sys.stdin.readline

n=int(input())
a=[int(x) for x in input().split()]

d={}
for i in range(n):
	if a[i]-1 in d:
		d[a[i]]=d[a[i]-1]+1
	else:
		d[a[i]]=1
maxi=1
z=a[0]
for i in d:
	if d[i]>maxi:
		maxi=d[i]
		z=i
c=[]
for i in range(n-1,-1,-1):
	if a[i]==z:
		c.append(i+1)
		break
zp=c[0]		
z-=1
for i in range(zp,-1,-1):
	if a[i]==z:
		c.append(i+1)
		z-=1

print(maxi)
print(*c[::-1])				
