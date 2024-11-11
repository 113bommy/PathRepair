x = int(input())
L = [int(i) for i in input().split()]
L.sort()
L = L[::-1]
a = 0
c = 0
A = []
while len(L) >= 2:
    if L[0] == L[1] or L[0] == L[1]+1:
            A.append(L[1])
            L.pop(0)
            L.pop(0)

    else:
        L.pop(0)
try:
    while c < len(A):
        a += A[c]*A[c+1]
        c += 2
    print(a)
except IndexError:
    print(0)