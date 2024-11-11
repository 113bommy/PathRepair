a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
d = list(map(int, input().split()))
e = list(map(int, input().split()))
s = 0
for i in range(len(a)):
    if a[i]==1:
        if i<=2:
            s=4-i
        else:
            s=i

for i in range(len(b)):
    if b[i]==1:
        if i<=2:
            s=3-i
        else:
            s=i-1

for i in range(len(c)):
    if c[i]==1:
        if i<2:
            s=2-i
        elif i>=3:
            s=i-2
        else:
            s=0

for i in range(len(d)):
    if d[i]==1:
        if i<=2:
            s=3-i
        else:
            s=i-1

for i in range(len(e)):
    if e[i]==1:
        if i<=2:
            s=4-i
        else:
            s=i

print(s)