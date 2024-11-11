N=int(input())

answer=0
import math
for m in range(1,math.ceil(math.sqrt(N+1/4)-1/2)):
    if N%m==0:
       answer+=N/m-1
print(int(answer))