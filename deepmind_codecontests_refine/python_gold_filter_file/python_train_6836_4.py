n,k = [int(x) for x in input().split()]

L = [int(x) for x in input().split()]

D = {}
for i in range(0,n):
    if not L[i] in D:
        D[L[i]] = i+1
if len(D) >= k:
    print('YES')
    count = 0
    for i in D.values():
        if count <= k-1:
            print(i, end = ' ')
            count += 1
else:
    print('NO')