for _ in range(int(input())):
    k,n,a,b=map(int,input().split())
    if k<=n*b:
        print(-1)
        continue
    print(max(0,min(n,(k-n*b)//(a-b))))
        
        
    