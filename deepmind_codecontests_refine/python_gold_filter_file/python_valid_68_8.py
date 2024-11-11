import math
for _ in range(int(input())):
    k = int(input())
    u = math.ceil(math.sqrt(k))
    d = math.floor(math.sqrt(k))
    if u==d:print(u,1)
    else:
        if k-(d**2)-1<u:print(k-(d**2),u)
        else:print(u,(u**2)-k+1)