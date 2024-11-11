ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
lx=lambda x:map(int,input().split(x))
#from math import log10 ,log2,ceil,factorial as fac,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
#from collections import Counter
 
 
 
for _ in range(t()):

    x,y=ll()

    if x==1 and y==1:
        print("YES")
    elif x==2 or x==3 and y<=3:
        print("YES")
    elif x>3:
        print("YES")
    else:
        print("NO")
    
'''
    

'''
    
#f()
