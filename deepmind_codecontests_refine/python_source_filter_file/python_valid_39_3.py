import sys
input = sys.stdin.readline
for _ in range(int(input())):
    b,l = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    w,h = map(int,input().split())
    ans = 10**18
    if x2-x1+w <= b:
        ans = min(ans,max(0,w-x1))
        ans = min(ans,max(0,x2-(b-w)))

    if y2-y1+h <= l:
        ans = min(ans, max(0, l - y1))
        ans = min(ans, max(0, y2 - (l - h)))

    if ans == 10**18:
        ans = -1

    print(ans)