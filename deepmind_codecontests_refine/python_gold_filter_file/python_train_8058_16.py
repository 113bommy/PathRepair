
n, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = set()
C = [0]*n
D = []

for i in range(n-1, -1, -1):
    B.add(A[i])
    C[i] = len(B)

for i in range(m):
    x = int(input())
    print(C[x-1])