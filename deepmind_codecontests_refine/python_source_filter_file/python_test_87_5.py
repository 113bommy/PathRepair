for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    m=0
    for i in range(n):
        m=max(0,(a[i]-(i+1)))
    print(m)