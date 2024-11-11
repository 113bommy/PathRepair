n=int(input())
a=list(reversed(list(map(int,input().split()))))
if a[0]>2:
	print("-1")
	exit()
a1,a2=2,2
for i in range(1,n):
	a1+=(a[i]-a1%a[i])%a[i]
	pre=a2
	a2+=a[i-1]-1
	a2-=a2%a[i]
	if a2<pre:
		print("-1")
		exit()
print(a1,a2+a[n-1]-1)