ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
#from math import log10 ,log2,ceil,factorial as f,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
from collections import Counter


#for _ in range(t()):
n=t()
a=list(ss())


if len(a)%2==0 :
        
    
    x=0
    j=n-a[::-1].index("(")-1
    flag=0
    #print(j,a[j])
    for i in range(n):
        if a[i]=="(":
            x+=1
        else:
            if x>0:
                x-=1
            else:
                if i<j and flag==0:
                    
                    a.insert(i,"(")
                    a.pop(j+1)
                    x+=1
                    flag=1
                else:
                    x-=1
                    break
    #print(a)
    if x==0:
        print("YES")
    else:
        print("NO")
else:
    print("NO")
    
            
