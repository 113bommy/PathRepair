# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
n,m=map(int,input().strip().split()[:2])
l=list(map(int,input().strip().split()[:n]))
k=sum(l[:n-1])
if m>=k:
	print('YES')
else:
	print('NO')