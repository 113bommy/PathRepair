for _ in range(int(input())):
    n,m = map(int,input().split())
    l = list(map(int,input().split()))
    if m<n:
        print(-1)
        continue
    print(2*sum(l))
    for i in range(1,n):
        print(i,i+1)
    print(n,1)