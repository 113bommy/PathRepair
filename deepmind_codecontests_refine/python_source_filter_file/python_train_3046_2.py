for _ in range(int(input())):
  n,k=map(int,input().split())
  l=list(map(int,input().split()))
  d={}
  ans=0

  for i in range(n):
    we=l[i]%k
    no=k-we
    if no not in d:
      d[no]=1
    elif no!=k:
      d[no]+=1
      
  for i in d:
    if i!=k:
      we=i+(d[i]-1)*k
    ans=max(ans,we)
    
  if ans!=0:
    ans+=1
  print(ans)
