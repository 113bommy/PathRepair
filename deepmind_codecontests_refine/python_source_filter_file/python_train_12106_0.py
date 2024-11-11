import sys
input = sys.stdin.readline
t  = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    row=[]
    col=[]
    for i in range(n):
        row.append(list(map(int,input().split())))
    for i in range(m):
        col.append(list(map(int,input().split())))
    for i in col[0]:
        for j in row:
            if i == j[0]:
                print(*j)

