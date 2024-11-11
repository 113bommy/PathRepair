import sys
def get_ints(): return list(map(int, sys.stdin.readline().strip().split()))
t=int(input())
for _ in range(t):
    n,m=get_ints()
    a=[]
    for i in range(n):
        a.append(get_ints())
    for i in range(n):
        for j in range(m):
            if (i+j)%2==0:
                if a[i][j]%2!=0:
                    a[i][j]=a[i][j]+1
            else:
                if a[i][j]%2!=1:
                    a[i][j]=a[i][j]+1
    for i in range(n):
        print(*a[i])