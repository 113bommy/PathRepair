from collections import defaultdict
import math
x=int(input())
ans=0
for i in range(2,x+1):
    ans+=((i-1)/i)
ans+=1
print(ans)