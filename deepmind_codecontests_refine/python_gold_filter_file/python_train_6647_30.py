N=int(input())
A=[int(i) for i in input().split()]
ans=True

if sum(A)*2%(N*(N+1))!=0:
        ans=False
k=sum(A)*2/(N*(N+1))


d=[A[i+1]-A[i]-k for i in range(N-1)]
d.append(A[0]-A[N-1]-k)
for i in range(N):
        if d[i]>0 or d[i]%N!=0:
                ans=False
if ans:
        print("YES")
else:
        print("NO")