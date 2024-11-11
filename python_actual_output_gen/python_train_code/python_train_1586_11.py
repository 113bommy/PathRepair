a,b,m=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
ans=min(A)+min(B)
for i in range(m):
  x,y,c=map(int,input().split())
  k=A[x]+B[y]-c
  if k<ans:
    ans=k
print(ans)