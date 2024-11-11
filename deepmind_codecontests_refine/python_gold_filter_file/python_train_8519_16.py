n = int(input())
A = list(map(int,input().split()))

A.sort()
v = A[-1] - A[0]
if v >= 2:
    print('No')
elif v == 0:
    if A[0]*2 <= n or A[0] == n-1:
        print('Yes')
    else:
        print('No')
else:
    x = A.index(A[-1])
    y = A[0] - x + 1
    if y > 0 and y*2 <= n-x:
        print('Yes')
    else:
        print('No')
