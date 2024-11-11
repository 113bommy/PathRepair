def check(y1, y2, n):
    for i in range(n):
        if y1[i][1] != y2[i][1]:
            return "YES"
    return "NO"


n = int(input())
eps = 10**(-5)
x1, x2 = map(int, input().split())
y1 = list()
y2 = list()
for i in range(n):
    k, b = map(int, input().split())
    f = lambda x: k * x + b
    y1.append((f(x1 + eps), i))
    y2.append((f(x2 - eps), i))
y1.sort()
y2.sort()
print(check(y1, y2, n))
