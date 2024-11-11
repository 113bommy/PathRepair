# import sys
# sys.stdin=open("input.in","r")
n=int(input())
l=[]
for i in range(n):
	m=list(map(int,input().split()))
	sum1=0
	for i in range(4):
		sum1=sum1+m[i]
	l.append(sum1)
c=l[0]
l.sort(reverse=True)
print(l)
print(l.index(c)+1)
