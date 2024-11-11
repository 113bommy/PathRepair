def f(k):
    div, mod = divmod(k, n)
    x,y = div*v[n][0]+v[mod][0], div*v[n][1]+v[mod][1]
    #print(x,y)
    if abs(x2-(x1+x))+abs(y2-(y1+y)) > k:
        return False
    return True

x1,y1 = list(map(int,input().split()))
x2,y2 = list(map(int,input().split()))
n = int(input())
s = input()

vx, vy = 0, 0
v = [(vx, vy)]
for i in s:
    if i == 'U':
        vy += 1
    elif i == 'D':
        vy -= 1
    elif i == 'L':
        vx -= 1
    else:
        vx += 1
    v.append((vx,vy))

l = 0
#r = abs(x2-x1) + abs(y2-y1)
r = 10**10
while r-l > 1:
    med = (r+l)//2
    if f(med):
        r = med
    else:
        l = med
if f(l):
    r = l
if r == 10**10:
    print(-1)
else:
    print(r)

