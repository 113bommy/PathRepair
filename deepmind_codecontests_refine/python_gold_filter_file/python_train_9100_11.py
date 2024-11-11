n,m=map(int,input().split(" "))
import math
X=[int(x) for x in input().split(" ")]
if(sum(X)==0):
    print(0)
if(sum(X)!=0):
    print(math.ceil(abs(sum(X))/m))    