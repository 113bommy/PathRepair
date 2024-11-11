n,l = map(int,input().split())

A = [int(i) for i in input().split()]
A.sort()

L = []

L.append(A[0])
for i in range(len(A) - 1):
    L.append((A[i+1] - A[i])/2)

L.append(A[-1] - l)

print(max(L))