for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=0
    x=0
    for i in range(n):
        s+=l[i]
        x=x^l[i]
    print(s,x)
    if(s==2*x):
        print(0)
        print()
    else:
        if(x==0):
            print(3)
            print(2,2,s+4)
        else:
            print(2)
            print(x,s+x)
        
        