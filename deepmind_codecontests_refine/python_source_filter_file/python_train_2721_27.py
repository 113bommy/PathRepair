import math
n = math.ceil(int(input())/2)
l = list(map(int,input().split()))
o = l.count(0)
t = 0
t1 = 0
for i in l:
    if i < 0:
        t += 1
    elif i > 0:
        t1 += 1
if t>t1+o:
    print(-1)
elif t1 > t+o:
    print(1)
else:
    print(0)
        
            
