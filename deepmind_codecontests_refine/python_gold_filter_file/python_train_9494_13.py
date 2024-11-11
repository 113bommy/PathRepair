import math
t=int(input())
for i in range(t):
    n=int(input())
    a,b,c=list(map(int,input().strip().split()))
    d=input()
    r=d.count('R')
    p=d.count('P')
    s=d.count('S')
    e=min(a,s)
    f=min(b,r)
    g=min(c,p)
    n1=math.ceil(n/2)
    arr=[0]*n
    if e+f+g>=n1:
        print('YES')
        for j in range(n):
            if d[j]=='R'and b>0:
                arr[j]='P'
                b=b-1
            elif d[j]=='P' and c>0:
                arr[j]='S'
                c=c-1
            elif d[j]=='S' and a>0:
                arr[j]='R'
                a=a-1
        for j in range(n):
            if arr[j]==0:
                if a>0:
                    arr[j]='R'
                    a=a-1
                elif b>0:
                    arr[j]='P'
                    b=b-1
                elif c>0:
                    arr[j]='S'
                    c=c-1
        print(''.join(arr))         
    else:
        print('NO')