# import sys
# input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if a==sorted(a):
        print(0)
    else:
        e=0
        b=[]
        for i in range(n):
            if a[i]!=i+1:
                e=1
                b.append(i)
        b.sort()
        c=min(b)
        for i in range(len(b)):
            b[i]-=c
        d=[i for i in range(len(b))]
        if d==b:
            e=0
        if e==1:
            print(2)
        else:
            print(1)