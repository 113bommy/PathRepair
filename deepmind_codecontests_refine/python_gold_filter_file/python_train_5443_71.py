import math
t=int(int(input()))
for k1 in range(t):
    l, r=map(int, input().rstrip().split())
    g=max(l, r)+1
    if (l%g)>=(g/2) and (r%g)>=(g/2):
        print('YES')
    else:
        print('NO')