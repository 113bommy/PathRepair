import math
t=int(input())
for _ in range (t):
    n=int(input())
    l=list(map(int, input().split()))
    total=sum(l)
    avg=total/n
    avgr=total//n
    if avg==avgr:
    	print (0)
    else:
    	c=round(((avg-avgr)*n))
    	ans=(c*(n-c))
    	
    	print (int(ans))