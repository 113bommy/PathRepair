d = int(input())
X, Y = map(int, input().split())

x = int(X)
y = int(Y)
ans = 0
while ('7' not in str(x * 10 + y)):
    ans += 1
    for i in range(d):
        y -= 1
        if (y < 0):
            y = 59
            x -= 1
            if (x == -1):
                x = 23
print(ans)
