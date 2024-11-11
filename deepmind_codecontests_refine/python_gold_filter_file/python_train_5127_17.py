for _ in range(int(input())):
    # n=int(input())
    # a=list(map(int,input().split()))
    n,k=map(int,input().split())
    if n%2==0: print(n+2*k)
    elif n%3==0: print(n+3+2*(k-1))
    else:
        i=5; f=0
        while i*i<=n:
            if n%i==0: f=1; break
            i+=1
        if f: print(n+i+2*(k-1))
        else: print(n+n+2*(k-1))