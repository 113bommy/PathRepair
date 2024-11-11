# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
n,m=map(int,input().strip().split()[:2])
k=list(map(int,input().strip().split()[:n]))
p=sum(k)
l=abs(p)//m
if p>0:
	if p%m==0:
		print(l)
	else:
		print(l+1)
elif p<0:
	if p%m==0:
		print(l)
	else:
		print(l+1)
else:
	print(0)