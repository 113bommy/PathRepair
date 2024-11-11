import math
m,d=map(int,input().split())
if m==2:
    print(math.ceil((20+d)/7)+1)
elif m in [1,3,5,78,10,12]:
    print(math.ceil((23 + d) / 7) + 1)
else:
    print(math.ceil((22 + d) / 7) + 1)
