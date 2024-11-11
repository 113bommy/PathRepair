N=int(input())
A=list(map(int,input().split()))
i,j,ans=0,0,0
while i<N:
    j=i
    while j<N and A[j]==A[i]: j+=1
    k=j
    while k<N and A[i]<A[j] and A[k-1]<=A[k]: k+=1
    while k<N and A[i]>A[j] and A[k-1]>=A[k]: k+=1
    ans+=1
    i=k
print(ans)