from math import ceil, floor
A = []
B = {}
for i in range(int(input())):
    a = int(input())
    if a/2%1!=0:
        B[len(A)] = a/2
    A += [a/2]
s = 0
for i in B:
    if s == 0:
        A[i] = ceil(B[i])
        s = 1
    else:
        A[i] = floor(B[i])
        s = 0
for i in A:
    print(i)
