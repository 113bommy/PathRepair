from math import sqrt
n, r = map(int, input().split())
r2 = r**2
*X, = map(int, input().split())
Y = [0]*n
ans = []
for i in range(n):
    y = 2
    for j in range(i):
        diff = abs(X[i] - X[j])
        if diff == 2*r:
            y = max(y, Y[j])
        elif diff < 2*r:
            y = max(y, sqrt(4*r2 - diff**2) + Y[j])
    Y[i] = y
    ans.append("%.010f" % Y[i])
print(*ans)
