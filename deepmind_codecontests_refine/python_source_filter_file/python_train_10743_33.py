t = int(input())
for i in range(t):
    n,m = map(int,input().split())
    l1 = list(map(int,input().split()))
    if(m!=n):
        print(-1)
        continue
    print(2*sum(l1))
    for i in range(n-1):
        print(i+1,i+2)
    print(n,1)