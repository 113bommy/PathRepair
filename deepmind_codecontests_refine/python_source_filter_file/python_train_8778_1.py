n,m = map(int,input().split())
A = []
for i in range(m):
    a,b = map(int,input().split())
    A.append([b,a])
A.sort()
#print(A)
i=m-1
ans=0
while(n>0):
    ans+=A[i][0]*min(n,A[i][1])
    n-=A[i][1]
    i-=1
print(ans)