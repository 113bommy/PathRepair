import sys
N=int(input())
for i in range(N):
    x,y,t=map(int,input().split())
    if (x+y)%2==t%2 and x+y<=t:
        pass
    else:
        print('NO')
        sys.exit()
print('YES')
