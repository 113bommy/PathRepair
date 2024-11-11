q=int(input())
for i in range(q):
    l1,r1,l2,r2=map(int,input().split())
    if l1>=l2:
        a=r1
        b=l2
    else:
        a=l1
        b=r2
    print(a,end=' ')
    print(b)