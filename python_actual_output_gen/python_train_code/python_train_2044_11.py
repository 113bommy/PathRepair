n = int(input())
A = list(map(int, input().split()))

ans = 0
up = dn = False
pre = A[0]
for a in A[1:]:
    if pre < a:
        up = True
    elif pre > a:
        dn = True
    if up and dn:
        ans += 1
        up = dn = False
    pre = a

print(ans)
