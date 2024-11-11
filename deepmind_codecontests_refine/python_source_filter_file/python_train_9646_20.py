ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
#from math import log10 ,log2,ceil,factorial as f,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
from math import sqrt


l=list(map(int,ss()))
p=len(l)
ans=3000000000
for n in range(1,2**p):
	c=1
	t=0
	st=0
	while n:
		if n&1:
			t=t*10+l[c-1]
			if t:
			    st+=1
		n=n>>1
		c+=1
		
	if sqrt(t).is_integer():
	    
	    ans=min(p-st,ans)
	    #print(t,st,ans)
if ans!=3000000000:
    print(ans)
else:
    print(-1)