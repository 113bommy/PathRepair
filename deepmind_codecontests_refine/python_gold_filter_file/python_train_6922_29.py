nA, nB = input().split()
k, m = input().split()

nA = int(nA)
nB = int(nB)
k = int(k)
m = int(m)

A = list(map(int, input().split()))
B = list(map(int, input().split()))

if k - 1 < nA and nB >= m:
    if A[k-1] < B[nB - m]:
        print("YES")
    else:
        print("NO")
else:
    print("NO")