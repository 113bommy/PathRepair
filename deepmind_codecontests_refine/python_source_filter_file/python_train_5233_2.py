import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m=map(int,input().split())
    if 2*n <=m:
        print(n,2*n)
    else:
        print(-1)
