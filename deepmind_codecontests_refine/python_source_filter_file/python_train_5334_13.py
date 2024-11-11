t = int(input())
for _ in range(t):
    a,b,c,d = map(int,input().split())
    x,y,x1,y1,x2,y2 = map(int,input().split())
    ans = True
    if x-a+b<x1 or x-a+b>x2 or(x1==x2 and (a>0 or b>0)):
        ans = False
    if y-c+b<y1 or y-c+b>y2 or(y1==y2 and (c>0 or c>0)):
        ans = False
    print("Yes" if ans else "No")