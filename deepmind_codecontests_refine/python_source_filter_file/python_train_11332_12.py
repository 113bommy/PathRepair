import sys
n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]

for i in range(n-m):
    for j in range(n-m):
        A = [a[s][i:i+m] for s in range(j,j+m)]
        if A == b:
            print("Yes")
            sys.exit()
print("No")