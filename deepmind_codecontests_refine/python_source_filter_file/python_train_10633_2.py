import sys
input = sys.stdin.readline

n,m=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]
B=[list(map(int,input().split())) for i in range(n)]

LISTA=[[] for i in range(n+m+1)]
LISTB=[[] for i in range(n+m+1)]

for i in range(n):
    for j in range(m):
        LISTA[i+j].append(A[i][j])
        LISTB[i+j].append(B[i][j])

for i in range(n+m+1):
    if set(LISTA[i])!=set(LISTB[i]):
        print("NO")
        sys.exit()

else:
    print("YES")
