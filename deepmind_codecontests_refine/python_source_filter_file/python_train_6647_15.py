import sys
input = sys.stdin.readline
n = int(input())
A = list(map(int,input().split()))
B = []
for i in range(n):
    B.append(A[i] - A[i-1])

m = max(B)
no = 0

if m < 0:
    no = 1
elif m == 0:
    if A[0] != n*(n+1)//2:
        no = 1
else:
    c = 0
    for i in range(n):
        if (m - B[i]) % n > 0:
            no = 1
        else:
            c += (m - B[i]) // n

    if c != m:
        no = 1
    if sum(A) != m * n*(n+1)//2:
        no = 1

if no==1:
    print("NO")
else:
    print("YES")