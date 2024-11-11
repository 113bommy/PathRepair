import copy
N = int(input())
A = input().split()
B = copy.copy(A)
boo = 1
while boo:
    boo = 0
    for i in range(N-1):
        if A[i][1] > A[i+1][1]:
            A[i], A[i+1] = A[i+1], A[i]
            boo = 1
print(*A)
print("Stable")
for i in range(N):
    mi = i
    for j in range(i,N):
        if B[mi][1] > B[j][1]:
            mi = j
    B[i], B[mi] = B[mi], B[i]
if A==B:
    print(*B)
    print("Stable")
else:
    print(*B)
    print("Not stable")

