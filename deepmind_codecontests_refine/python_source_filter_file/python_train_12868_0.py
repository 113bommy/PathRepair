n = int(input())
t = list(map(int, input().split()))
s = a = b = 0
for i in range(n):
    a = max(a, t[i] - i)
    b = max(b, t[-1 - i] - i)
x = (b - a + n) // 2
y = 0
for i in range(x):
    s += max(y - t[i], 0)
    y = max(t[i], y) + 1
y = 0
for i in range(n - x):
    s += max(y - t[-1 - i], 0)
    y = max(t[-1 - i], y) + 1
print(s)