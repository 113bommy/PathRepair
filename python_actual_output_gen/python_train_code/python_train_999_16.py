n=int(input())

arr=list(map(int,input().split()))
s=2
m=0

for i in range(2,n):
	if arr[i-1]+arr[i-2]==arr[i]:
		s+=1
		if s>m:
			m=s
	else:
		s=2

if n==1 or n==2:
	print(n)
else:
	print(m)