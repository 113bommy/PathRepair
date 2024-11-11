for _ in range(int(input())):
    n=int(input())
    b,c=[],[]
    if n==2 or n==3:
        print(-1)
        continue
    if n==4:
        a=[3,1,4,2]
        print(*a)
        continue
    if n==5:
        a=[4,2,5,1,3]
        print(*a)
        continue
    a=[6,4,2,5,1,3,5]
    for i in range(7,n+1):
        if i%2==0:
            b.append(i)
        if i%2==1:
            c.append(i)
    b.reverse()
    a=b+a+c
    print(*a)