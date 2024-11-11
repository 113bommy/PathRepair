n,k = list(map(int,input().split()))
a = list(map(int,input().split()))
sub = 0
sp = 0
a.sort()

for i in range(0,k):
    if sp == n:
        print(0)
        continue
    while(a[sp] == sub):
        sp += 1
        if sp == n:
            break
    if sp == n:
        print(0)
        continue
    print(a[sp]-sub)
    sub += a[sp]
    sp += 1