import math

n = int(input())
P = []
#very small でWAなので、rで割ってかけ直すのをやめてみる
#atanを使ってみる
#0またいだときがおかしいか
for i in range(n):
    x, y = map(int, input().split( ))
    rad = math.atan2(x, y)
    P.append([rad, x, y])

P.sort()
P = P + P 


x0 = 0
y0 = 0

mx = 0

for i in range(n):
    vx = 0
    vy = 0
    for j in range(n):
        vx += P[i+j][1]
        vy += P[i+j][2]
    	v = vx**2 + vy**2
    	mx = max(v,mx)
print(math.sqrt(mx))
