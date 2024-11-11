n = int(input())
a = list(map(int, input().split()))
mn = min(a)
mx = max(a)
ans = mn + 1
av = 0
for i in a:
    if abs(i - mn - 1) > 1:
        av += abs(i - mn - 1)
for t in range(mn + 2, mx):
    summ = 0
    for i in a:
        if abs(i - t) > 1:
            summ += abs(i - t) - 1
    if summ < av:
        av = summ
        ans = t
print(ans, av)
