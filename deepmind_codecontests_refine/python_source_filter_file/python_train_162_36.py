def countdiv(A,B,M): 
    if (A % M == 0): 
        return ((B / M) - (A / M)) + 1
    return ((B / M) - (A / M)) 
l,r=map(int,input().split())
l1=[]
import math
for i in range(2,10):
    l1.append([i,countdiv(l,r,i)])
l1.append([l,1])
l1.append([r,1])
print(max(l1,key=lambda x:x[1])[0])
