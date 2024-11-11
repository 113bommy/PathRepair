import math,bisect
from collections import Counter,defaultdict
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
n,k=M()
a=LI()
medianIndex = n // 2
a = a[medianIndex:]
left = 1
right = 10**10
while left < right:
    mid = (left + right + 1) // 2
    count = 0
    for i in range(len(a)):
        count += max(0, mid - a[i])
    if count > k:
        right = mid - 1
    else:
        left = mid
print(left)



        









        
        
            


        



    









    

            







        
