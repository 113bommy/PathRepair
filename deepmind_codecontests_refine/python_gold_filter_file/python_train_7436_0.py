import math
n,k=map(int,input().split())
p=input()
x=math.ceil(n/2)
if k<=x:
    for _ in range(k-1):
        print("LEFT")
    for i in range(len(p)):
        print("PRINT "+p[i])
        if i!=len(p)-1:
            print("RIGHT")
else:
    for _ in range(n-k):
        print("RIGHT")
    p=p[::-1]
    for i in range(len(p)):
        print("PRINT "+ p[i])
        if i!=len(p)-1:
            print("LEFT")

