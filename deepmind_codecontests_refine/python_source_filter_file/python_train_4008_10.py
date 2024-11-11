n, w = map(int, input().split())
v = list(map(int, input().split()))
v.sort()

x = v[n] / v[0]
if x >= 2:
    x = v[0]
else:
    x = v[n]
sum = x*n + x*n*2
if sum > w:
    sum = w
print(sum)
