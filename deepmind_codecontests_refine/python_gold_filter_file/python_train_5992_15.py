# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
b=sum(a)/(n/2)
for i in range(n):
	for j in range(i+1,n):
		if a[i]+a[j]==b:
			print(i+1,j+1)
			a[j]=0
			break
