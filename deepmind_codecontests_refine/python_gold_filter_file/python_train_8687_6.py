def calc(a,b):
    x, y = [], []
    for i in range(20):
        if a>0:
            x.append(a%2)
            a = a//2
        else:
            x.append(0)
    for i in range(20):
        if b>0:
            y.append(b%2)
            b = b//2
        else:
            y.append(0)
    cont = 0
    for i in range(20):
        if x[i] != y[i]:
            cont += 1
    return cont


n, m, k = map(int, input().split())
arr = []
for i in range(m+1):
    a = int(input())
    arr.append(a)
ans = 0
for i in range(m):
    cnt = calc(a,arr[i])
    if cnt <= k:
        ans += 1
print(ans)