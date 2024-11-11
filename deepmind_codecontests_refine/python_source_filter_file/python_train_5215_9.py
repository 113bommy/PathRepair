a = list(map(int, input()))
for i in range(len(a)):
    a[i] = a[i] % 3
s = 0
ans = 0
for i in range(len(a)):
    s += a[i]
    if a[i] % 3 == 0:
        s = 0
        ans += 1
    if s % 3 == 0:
        s = 0
        ans += 1
    elif s != a[i] and abs( a[i] - a[i-1] ) == 1:
        s = 0
        ans += 1
print(ans)