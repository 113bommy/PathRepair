n = int(input())
a = list(map(int,input().split()))
for i in a:
    if i!=a[0]:
        break
else:
    print(-1)
    exit()
s1 = sum(a[:n])
s2 = sum(a[n:])
if s1!=s2:
    print(*a)
else:
    for i in range(n):
        for j in range(n,2*n):
            if a[i]!=a[j]:
                a[i],a[j] = a[j],a[i]
                print(*a)
                exit()
