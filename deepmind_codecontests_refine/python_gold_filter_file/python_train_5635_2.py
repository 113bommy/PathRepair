q = int(input())

for i in range(q):
    n,k = map(int,input().split())
    if n > 31:
        print("YES",n-1)
        continue
    a = [0]
    for i in range(1,n+1):
        a.append(a[i-1]*4+1)
    if a[n] < k:
        print("NO")
        continue
    if n == 2 and k == 3:
        print("NO")
        continue
    p = 0
    q = 2
    while p+q-1 <= k and n > 0:
        p += q-1
        q *= 2
        n -= 1
    print("YES",n)
