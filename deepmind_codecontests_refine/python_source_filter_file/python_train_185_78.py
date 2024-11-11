import math
import copy
 
n,p=map(int,input().split())
a=math.floor(p**(1/n))
#print(a)
for i in range(a,0,-1):
    if i==1:
        print(i)
        break
    p_s=copy.deepcopy(p)
    cnt=0
    while p_s%i==0:
        cnt+=1
        p_s//=i
        if cnt>=n:
            print(i)
            exit()