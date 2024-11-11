n,k=map(int,input().split())
l=list(map(int,input().split()))
ans=[]
for i in range(n-k+1):
  ans.append(min(abs(l[i])+abs(l[i]-l[i+k-1]),abs(l[i+k-1])+abs(l[i+k-1]-l[i])))
print(min(ans))