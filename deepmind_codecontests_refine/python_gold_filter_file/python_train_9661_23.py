import sys
N = int(input())
A = sorted(list(map(int,input().split())))

mn = A[0]
mx = A[-1]
if N ==2:
    print(A[1] - A[0])
    print(A[1],A[0])
    sys.exit()
ope = []
for a in A[1:-1]:
    if a <=0:
        ope.append([mx, a])
        mx -= a
    else:
        ope.append([mn, a])
        mn -= a
ope.append([mx,mn])
print(mx-mn)
for o in ope:
    print(o[0],o[1])