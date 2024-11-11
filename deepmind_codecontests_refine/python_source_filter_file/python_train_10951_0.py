q = int(input())

ans = []

for _ in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    was = False
    prev = 0
    c = []
    for i in range(n):
        c.append(b[i]-a[i])

    counter = 0
    prev = None
    right = []
    for el in c:
        if (el!=prev):
            right.append(el)
        prev = el

    counter = 0
    ok = True
    for i in right:
        if (i<0):
            ok = False
        elif (i>0):
            counter+=1
    if ok and (counter==1):
        ans.append('YES')
    else:
        ans.append('NO')

print('\n'.join(ans))
