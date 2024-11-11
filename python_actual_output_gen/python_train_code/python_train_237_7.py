N=int(input())
A=list(map(int,input().split()))
M=int(input())
B=list(map(int,input().split()))
ans=0
for i in range(N):
    for j in range(M):
        if B[j]%A[i]:
            temp=B[j]//A[i]
            ans=max(ans,temp)
count=0
#print(ans)
for i in range(N):
    for j in range(M):
        if B[j]/A[i]==ans:
            count+=1
           # print(B[j],A[i])
print(count)
