n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=0
for i in range(n-2):
  a=l[i]
  
  for j in range(i+1,n-1):
    b=l[j]
    k=j
    while k<n and l[k]<a+b:
      k+=1
    ans+=k-j-1
print(ans)


