def f(n):
    if n==0:
        return 0
    for k in range(1,8):
        for j in range(1,8):
            if j|k==n and j!=n and k!=n:
                a[n]=min(a[n],f(j)+f(k))
    return a[n]

n = int(input())
a = 8*[1e8]
for _ in range(n):
    val, s = input().split()
    s = sum(map(lambda x: 1<<(ord(x)-ord('A')), s))
    a[s] = min(a[s],int(val))

out = f(7)
print(a)
if out == 1e8:
    print(-1)
else:
    print(out)