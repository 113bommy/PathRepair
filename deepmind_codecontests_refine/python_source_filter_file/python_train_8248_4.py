for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    flag=0
    for i in range(0,max(a)+1):
        b=[]
        for j in a:
            b.append(i^j)
        b.sort()
        if(b==a):
            print(i)
            flag=1
            break
    if(flag==0):
        print("-1")