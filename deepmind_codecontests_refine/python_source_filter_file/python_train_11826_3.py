b=int(input())
l=input().split(' ')
a=[]
for n in l:
	a.append(int(n))
a.sort()
d=a[1]-a[0]
n=1
for k in range(len(a)-1):
	if d>a[k+1]-a[k]:
		d=a[k+1]-a[k]
		n=1
	elif d==a[k+1]-a[k]:
		n+=1
print (d,end=' ')
print (n)