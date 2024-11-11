import math 
a,b,c,d=map(int,input().split())
print("Yes") if math.ceil(c/a)>=math.ceil(a/d) else print("No")