N = int(input())
A = list(map(int,input().split()))
A.sort()
mn,mx = A[0],A[-1]

from collections import Counter
ctr = Counter(A)

if ctr[mx] < 2:
    print('Impossible')
    exit()
if (mn == 1 and ctr[mn] > 1) or ctr[mn] > 2:
    print('Impossible')
    exit()

for n in range(mn,mx+1):
    if ctr[n]==0:
        print('Impossible')
        exit()
print('Possible')