# your code goes here# your code goes here
t=int(input())
for i in range (t):
	n,k=input().split(' ')
	n=int(n)
	k=int(k)
	cnt=0
	while n!=0:
		cnt=cnt+n%k
		n=n//k
		cnt=cnt+1
	cnt=cnt-1
	if i==t-1:
		print(cnt,end='')
	else:
		print(cnt)