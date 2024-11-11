import sys

n, m, k, q = list(map(int, sys.stdin.readline().strip().split()))
T = [0] * k
for i in range (0, k):
    T[i] = list(map(int, sys.stdin.readline().strip().split()))
    T[i][1] = T[i][1] - 1
    T[i][0] = T[i][0] - 1
T.sort() # treasures sorted by row
b = list(map(int, sys.stdin.readline().strip().split()))
b.sort()
for i in range (0, q):
    b[i] = b[i] - 1     # sorted safe columns
L = [b[0]] * m          # safe column left
R = [b[-1]] * m         # safe column right
R1 = [10 ** 6] * n      # leftmost treasure
R2 = [-1] * n           # rightmost treasure
n1 = 0                  # pathlength 1
n2 = 0                  # pathlength 2
for i in range (0, k):
    R1[T[i][0]] = min(R1[T[i][0]], T[i][1])
    R2[T[i][0]] = max(R2[T[i][0]], T[i][1])
for i in range (0, q):
    L[b[i]] = b[i]
    R[b[i]] = b[i]
for i in range (1, m):
    L[i] = max([L[i-1], L[i]])
    R[m-i-1] = min([R[m-i], R[m-i-1]])
r = 0
c1 = 0
c2 = 0
n1 = 0
n2 = 0
if R2[0] != -1:
    c1 = R2[0]
    c2 = R2[0]
    n1 = R2[0]
    n2 = R2[0]
for i in range (1, n):
    if R2[i] != -1:
        r, c1, c2, n2, n1 = i, R1[i], R2[i], i-r+abs(R1[i]-R2[i])+min([n1+abs(c1-L[c1])+abs(R2[i]-L[c1]), n2+abs(c2-L[c2])+abs(R1[i]-L[c2]), n1+abs(c1-R[c1])+abs(R1[i]-R[c1]), n2+abs(c2-R[c2])+abs(R1[i]-R[c2])]), i-r+abs(R1[i]-R2[i])+min([n1+abs(c1-L[c1])+abs(R2[i]-L[c1]), n2+abs(c2-L[c2])+abs(R2[i]-L[c2]), n1+abs(c1-R[c1])+abs(R2[i]-R[c1]), n2+abs(c2-R[c2])+abs(R2[i]-R[c2])])
print(min([n1, n2]))
