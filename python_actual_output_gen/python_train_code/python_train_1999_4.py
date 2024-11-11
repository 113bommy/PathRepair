# http://codeforces.com/problemset/problem/298/B

d = {'E':(1,0), 'S':(0,-1), 'W':(-1,0), 'N':(0,1)}

t,sx,sy,ex,ey = map(int, input().split())
s = input()

for i in range(t):
    dx,dy = d[s[i]]

    if abs(sx-ex+dx)<=abs(sx-ex) and abs(sy-ey+dy)<=abs(sy-ey):
        sx+=dx
        sy+=dy
    if sx==ex and sy==dy:
        print(i+1)
        exit()
print(-1)
