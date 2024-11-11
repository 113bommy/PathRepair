n,K = map(int,input().split())
X, Y = [], []
dots = []
for _ in range(n):
    x,y = map(int,input().split())
    dots.append((x,y))
    X.append(x)
    Y.append(y)
X.sort()
Y.sort()
ans = float('inf')
for i in range(n):
    for j in range(i+1, n):
        for k in range(n):
            for l in range(k+1, l):
                x1,x2 = X[i], X[j]
                y1,y2 = Y[k], Y[l]
                cnt = 0
                for dot in dots:
                    if x1<=dot[0]<=x2 and y1<=dot[1]<=y2:
                        cnt += 1
                if cnt >= K:
                    ans = min(ans, (x2-x1)*(y2-y1))
print(ans)