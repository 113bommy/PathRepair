N=int(input())
A=list(map(int,input().split()))
ans=N
A.sort()

asum=[A[0]]
j=1
for i in range(1,N):
    if asum[i-1]*2<A[i]:
        ans-=j
        j=1
    asum.append(asum[i-1]+A[i])
    j+=1

print(ans)