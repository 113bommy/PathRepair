q=int(input())
for i in range(q):
    l1,r1,l2,r2=map(int,input().split())
    if l1>=l2:
        a=l2
        b=r1
    else:
        a=l1
        b=r2
    print(a,end=' ')
    print(b)