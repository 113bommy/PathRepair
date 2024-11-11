n, b = map(int, input().split())
ch = 0
nch = 0
res = []
a = list(map(int, input().split()))
for i in range(n):
    if a[i] % 2 == 0:
        ch += 1
    else:
        nch += 1
    if nch == ch:
        if i != n - 1:
            res.append(a[i + 1] - a[i])

res.sort()
if ch != nch: 
    print(0)
elif len(res) == 0:
    print(0)
elif res[0] > b:
    print(0)
else:
    s = 0
    c = 0
    for i in range(len(res)):
        if s + res[i] <= b:
            s += res[i]
            c += 1
    print(c)