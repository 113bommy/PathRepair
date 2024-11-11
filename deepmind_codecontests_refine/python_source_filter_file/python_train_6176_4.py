n, m =map(int,input().split())
x, y =map(int,input().split())
k = int(input())
ans = 0
for i in range(k):
    x1, y1 =map(int,input().split())
    # print(111, x, y)
    if x1<0:
        tp = (x-1)//(-x1)
    elif x1>0:
        tp = (n-x)//(x1)
    else:
        tp = max(m, n)
    if y1<0:
        tp1 = (y-1)//(-y1)
    elif y1>0:
        tp1 = (m-1)//(y1)
    else:
        tp1 = max(m, n)
    # print(i, i, i, tp, tp1)
    tk = min(tp, tp1)
    ans += tk
    x+=(tk*x1)
    y+=(tk*y1)
    # print(x, y)
    
print(ans)