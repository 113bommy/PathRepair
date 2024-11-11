import math
import bisect
from collections import defaultdict
from collections import OrderedDict
for _ in range(int(input())):

    n,p,k = map(int,input().split())
    a = list(map(int,input().split()))

    k = 2
    sum_even = 0
    sum_odd  = 0
    ans = 0  
    

    a.sort()

    for i in range(n+1):
        x = a[i-1]
        

        if i%2 == 0:

            sum_even += x
            if sum_even <= p:
                ans = max(ans,i)
        else:
            sum_odd += x
            if sum_odd<= p:
                ans = max(ans,i)



    
    print(ans)
            

       
