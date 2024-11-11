import math
T = int(input())
for t in range(T):
    l = list(map(int,input().split()))
    health = l[0]
    ab = l[1]
    st = l[2]
    for i in range(ab):
        if (health>19):
            health = math.floor(health/2) + 10
    if (health > 10*st):
        print("NO")
    else :
        print("YES")