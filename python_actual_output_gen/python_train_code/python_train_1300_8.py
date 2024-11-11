for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=sum(l)
    if s%n==0:
        print(s//n)
    else:
        print((s+1)//n)