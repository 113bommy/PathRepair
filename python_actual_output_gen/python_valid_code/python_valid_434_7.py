for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split(" ")))
    a=0
    b=0
    for i in range(n):
        if l[i]==1:
            a=a+1
        elif l[i]==0:
            b=b+1
    if a==0 and b==0:
        print(0)
    else:
        if b==0:
            print(a)
        elif a==0:
            print(0)
        else:
            print(a*b*2)
    
    
