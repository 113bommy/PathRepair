def prime(n):
  if n==1:
    return False
  elif n==2 or n==3:
    return True
  else:
    for i in range(2,int(n**0.5)+1):
      if n%i==0:
        return False
    else:
      return True

ans=[0]*(10**5+1)
for i in range(3,10**5+1,2):
  if prime(i) and prime((i+1)//2):
    ans[i]=1
for i in range(1,10**5+1)=:
  ans[i]=ans[i]+ans[i-1]
q=int(input())
for i in range(q):
  l,r=map(int,input().split())
  print(ans[r]-ans[l-1])