for _ in [0]*int(input()):
    n,m=map(int,input().split())
    l=list(map(int,input().split()))
    if m<n:print(-1)
    else:
        print(sum(l)*2)
        for i in range(n):
            print(i+1,(i+1)%n+1)
