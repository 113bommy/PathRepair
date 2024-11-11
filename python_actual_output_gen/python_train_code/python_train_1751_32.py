def r(a, b):
    ans = a // b
    if a % b != 0:
        ans += 1
    return ans


n, B = map(int, input().split())
a = list(map(int, input().split()))
costs = []
ch, notch = 0, 0
for i in range(n):
    if a[i] % 2 == 0:
        ch += 1
    else:
        notch += 1
    if ch == notch:
        ch, notch = 0, 0
        if i < n - 1:
            costs.append(a[i + 1] - a[i])
costs.sort()
ans = 0
for i in costs:
    if B < i:
        break
    B -= i
    ans += 1
print(ans)
