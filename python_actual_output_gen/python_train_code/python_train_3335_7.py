N = int(input())
A = list(map(int,input().split()))

A = sorted(A)
plus = []
minus = []

for i in range(N):
    if i == 0:
        minus.append(A[i])
    elif i == N-1:
        plus.append(A[i])
    else:
        if A[i] > 0:
            plus.append(A[i])
        else:
            minus.append(A[i])

print(sum(plus)-sum(minus))
tmp = minus[0]
for i in range(len(plus)-1):
    print(tmp,plus[i])
    tmp -= plus[i]

A[0] = tmp
tmp2 = A[-1]
for i in range(len(minus)):
    print(tmp2,minus[i])
    tmp2 -= minus[i]
    

