import math

n = int(input())
l = list(map(int,input().split(" ")))
pc = 0
nc = 0
zc = 0
for i in l:
    if(i==0):
        zc+=1 
    elif(i>0):
        pc+=1 
    else:
        zc+=1 
x = math.ceil(n/2)
if(pc>=x):
    print(1)
elif(nc>=x):
    print(-1000)
else:
    print(0)