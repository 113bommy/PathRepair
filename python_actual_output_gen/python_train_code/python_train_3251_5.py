# your code goes here
n=int(input())
f=0
a=[int(i) for i in input().split()]
for i in range(1,n-1):
	if(a[i-1]+a[i]>a[i+1]):
		f=1
		break
if f==1:
	print('YES')
else:
	print('NO')