
n = int(input())
x = [0] * n
h = [0] * n

for i in range(0, n):
    x[i], h[i] = map(int, input().split())

ans = 0 
last = 0

for i in range(n):
    if i == 0 or i == n - 1:
        ans += 1
        last = x[i]
    elif last + h[i] < x[i]:
        ans += 1
        last = x[i]
    elif x[i] + h[i] < x[i + 1]:
        ans += 1
        last = x[i] + h[1]
    else:
        last = x[i]

print(ans)
