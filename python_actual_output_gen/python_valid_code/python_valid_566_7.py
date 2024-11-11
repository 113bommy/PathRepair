import sys
input=sys.stdin.readline

for i in range(int(input())):
    a,b,c,m=map(int,input().split())
    a,b,c=sorted([a,b,c])
    
    Min=max(b-(a+c+1), 0)
    Max=sum(max(i-1, 0) for i in (a,b,c))

    if Min<=m<=Max:
        print('YES')
    else:
        print('NO')
