nk = list(map(int, input().split()))
n = nk[0]
k = nk[1]

lst = list(map(int, input().split()))

e = 0
s = 0
for i in lst:
    if i == 1:
        e += 1
    else:
        s += 1
larg = 0
for b in range(1,k):
    a = 0
    x = e
    y = s
    while a*k + b <= n:
        if lst[a*k+b-1] == 1:
            x -= 1
        else:
            y -= 1
        a += 1
    if abs(x-y)>larg:
        larg = abs(x-y)
print(larg)


