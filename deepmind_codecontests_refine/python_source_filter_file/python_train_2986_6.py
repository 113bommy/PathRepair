n = int(input())
s = list(map(int, input().split()))
c = list(map(int, input().split()))
m = float("inf")
for j in range(1, n - 1):
    x = float("inf")
    y = float("inf")
    for i in range(j - 1):
        if s[i] < s[j]:
            x = min(x, c[i])
    for k in range(j + 1, n):
        if s[j] < s[k]:
            y = min(y, c[k])
    m = min(m, x + y + c[j])
if m == float("inf"):
    m = -1
print(m)
