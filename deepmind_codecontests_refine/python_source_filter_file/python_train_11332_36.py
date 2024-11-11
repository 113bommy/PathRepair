n,m = map(int,input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

f = 0
for i in range(n - m + 1):
    for j in range(n - m + 1):
        t = [k[j:j + m] for k in a[i:i + m]]
        if t == b: f = 1

print ("Yes" if f else "no")
