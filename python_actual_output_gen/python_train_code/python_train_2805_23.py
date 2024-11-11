n, t = map(int, input().split())
a = list(map(int, input().split()))

i = 0
res = "NO"
while i < n:
    i = (i+1) + a[i-1]
    if i == t:
        res = "YES"
        break
    elif i > t:
        res = "NO"
        break

print(res)
