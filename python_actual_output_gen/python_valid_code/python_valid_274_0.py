n,k=map(int,input().split())
arr=list(map(int,input().split()))
if k==1:
  print(max(arr))
  print(n)
  exit()
arr=[[arr[i],i] for i in range(n)]
arr=sorted(arr,reverse=True,key=lambda x:x[0])
tmp=[]
ans=0
for i in range(k):
  v,pos=arr[i]
  ans+=v
  tmp.append(pos)
tmp=sorted(tmp)
ans2=[]
for i in range(k-1):
  if i==0:
    ans2.append(tmp[i]+1)
  else:
    ans2.append(tmp[i]-tmp[i-1])
ans2.append(n-tmp[-2])
print(ans)
print(*ans2)