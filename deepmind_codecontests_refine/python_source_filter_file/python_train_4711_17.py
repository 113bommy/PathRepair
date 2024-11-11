t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    m=l[1]=l[0]
    for i in range(n-1):
        m=min(m,l[i+1]-l[i])
    print(m)