import math
n,k=map(int,input().split())
a=math.ceil(n/2)
print(2*(k-a)if(k<a)else 2*k-1)