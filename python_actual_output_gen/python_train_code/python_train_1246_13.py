n=int(input())
l=list(map(int,input().strip().split()))
l1=list(map(int,input().strip().split()))
s=sum(l)
l.sort()
r=l1[-1]+l1[-2]
if s<=r:
	print ("YES")
else:
	print ("NO")