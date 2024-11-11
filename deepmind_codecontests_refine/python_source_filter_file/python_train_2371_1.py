n=int(input())
Ns=list(map(int, input().split() ) ) 
ans=0
for i in range(n):
  for j in range(i,j):
    for k in range(j,n):
      a , b , c = sorted([Ns[i] , Ns[j] , Ns[k]])
      if a+b>c and a!=b and b!=c:
        ans+=1
print(ans)