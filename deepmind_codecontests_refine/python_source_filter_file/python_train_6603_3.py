n=int(input())
a=[]
b=[]
for i in range(n):
	x1=input().strip()
	x=list(x1)
	a.append(x)
	for j in x:
		b.append(j)
k=len(list(set(b)))
kj=0
for aj in b:
	if aj==a[0][1]:
		kj+=1
if k!=2:
	print("NO")
elif kj!=(n**2-2*n-1):
	print("NO")


else:
	pp=0
	p=0
	p1=n-1
	for kk in range(n-1):
		if (a[kk][p]==a[kk+1][p+1]) and (a[kk][p1]==a[kk+1][p1-1]):
			p+=1
			p1-=1
		else:
			pp=1
			break
	if pp==0:
		print("YES")
	else:
		print("NO")

		




