n, t = map(int, input().split())
a = sorted(map(int, input().split()))
count = 0
for i in range(0, n):
    if t > 1:
        count += t*a[i]
        t -= 1
    else:
        count += a[i]
print(count%1000001)