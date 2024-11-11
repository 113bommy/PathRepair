t=int(input())

for j in range(t):
    input()
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    t=list(map(int,input().split()))
    final=[10**10 for i in range(n)]

    for i in range(k):
        final[a[i]-1]=t[i]
    for i in range(1,n):
        final[i]=min(final[i-1]+1,final[i])
    for i in range(n-2,-1,-1):
        final[i]=min(final[i],final[i+1]+1)
    print(final)



