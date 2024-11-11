from collections import defaultdict
import math
x=int(input())
ans=x
for i in range(2,x+1):
    ans-=(1/i)
print(ans)