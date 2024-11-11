def divisor(n):
  ret=[]
  for i in range(1,int(n**0.5)+1):
    if n%i==0:
      ret.append(i)
      if n//i!=i:
        ret.append(n//i)
  return ret

n=int(input())
arr=list(map(int,input().split()))
pos=[]
for i in range(n):
  if arr[i]==1:
    pos.append(i)
cnt=sum(arr)
d=divisor(cnt)
if len(d)<=2:
  print(-1)
else:
  d=sorted(d)[1:-1]
  ans=10**10
  for val in d:
    if val%2==0:
      tmp=0
      for i in range(cnt//val):
        c1=pos[val*i+val//2-1]
        c2=pos[val*i+val//2]
        for j in range(val//2):
          tmp-=pos[val*i+j]
        tmp+=c1*val//2
        for j in range(val//2,val):
          tmp+=pos[val*i+j]
        tmp-=c2*val//2
        tmp+=(c2-c1)*val//2
      ans=min(ans,tmp)
    else:
      tmp=0
      for i in range(cnt//val):
        c=pos[val*i+val//2]
        for j in range(val//2):
          tmp-=pos[val*i+j]
        tmp+=c*val//2
        for j in range(val//2+1,val):
          tmp+=pos[val*i+j]
        tmp-=c*val//2
      ans=min(ans,tmp)
  print(ans)