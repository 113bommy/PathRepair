import math
n = int(input())
a = [list(map(int,input().split())) for _ in range(n)]
ans = 0
for x in range(-20,21):
    for y in range(-20,21):
        sx = 0
        sy = 0
        for v in a:
            if v[0]*x+v[1]*y>0:
                sx+=v[0]
                sy+=v[1]
        ans = max(ans,math.sqrt(sx*sx+sy*sy))
print(ans)