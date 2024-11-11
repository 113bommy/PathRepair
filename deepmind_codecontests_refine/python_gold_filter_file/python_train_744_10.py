q = int(input())
for _ in range(q):
    n = int(input())
    p = [int(x) for x in input().split()]
    if n in (1,2,3):
        print("YES")
        continue
    i = p.index(1)
    p += p
    if all(p[x] <= p[x+1] for x in range(i, i+n-1)) or all(p[x] >= p[x+1] for x in range(i+1,i+n)):
        print("YES")
    else :
        print("NO")