n = int(input())
s = list(map(int, input().split()))
c = []
f = 0
for i in range(n):
    c.append(input())
F = [[0, 0] for i in range(n)]
F[0][1] = s[0]
for i in range(1, n):
    if F[i - 1][0] != None and F[i - 1][1] != None and c[i - 1] <= c[i] and c[i - 1][::-1] <= c[i]:
        F[i][0] = min(F[i - 1][0], F[i - 1][1])
    elif F[i - 1][0] != None and c[i - 1] <= c[i]:
        F[i][0] = F[i - 1][0]
    elif F[i - 1][1] != None and c[i - 1][::-1] <= c[i]:
        F[i][0] = F[i - 1][1]
    else:
        F[i][0] = None
        f = 1
    c1 = c[i][::-1]
    if F[i - 1][0] != None and F[i - 1][1] != None and c[i - 1] <= c1 and c[i - 1][::-1] <= c1:
        F[i][1] = min(F[i - 1][0], F[i - 1][1]) + s[i]
        f = 0
    elif F[i - 1][0] != None and c[i - 1] <= c1:
        F[i][0] = F[i - 1][0] + s[i]
        f = 0
    elif F[i - 1][1] != None and c[i - 1][::-1] <= c1:
        F[i][1] = F[i - 1][1] + s[i]
        f = 0
    else:
        F[i][1] = None
if f == 1:
    print(-1)
else:
    if F[-1][0] != None and  F[-1][1] != None:
        print(min(F[-1][0], F[-1][1]))
    elif F[-1][0] != None:
        print(F[-1][0])
    else:
        print(F[-1][1])


