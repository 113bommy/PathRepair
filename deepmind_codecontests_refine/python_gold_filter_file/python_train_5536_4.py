n = int(input())
a = list(map(int, input().split()))
q = int(input())
s = [0 for i in range(len(a))]
f = [0 for i in range(q)]

for i in range(q):
    r = list(map(int, input().split()))
    if(r[0] == 1):
        s[r[1]-1] = i
        a[r[1]-1] = r[2]
    else:
        f[i] = r[1]

for i in reversed(range(0,q-1)):
    f[i] = max(f[i], f[i+1])

for i in range(n):
    a[i] = max(a[i], f[s[i]])

print(*a)