# import sys
# sys.stdin=open("input.in","r")
n,m=map(int,input().split())
m=(m%int(n*(n+1)/2))
for i in range(1,m+1):
	if((m-i)>=0):
		m-=i
	else:
		break
print(m)