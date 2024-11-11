t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=a[::-1]
    m=b[0]
    ans=0
    for j in range(n):
        if m>b[j]:
            ans+=1
            m=b[j]
    print(ans)