input()
A = list(map(int,input().split()))
x = A[0]//2
s = A[0]
C = {1}

for c,a in enumerate(A, 1):
    if a <= x:
        s += x
        C.add(c)

if s > sum(A)/2:
    print(len(C))
    print(*C)
else:
    print(0)