N=list(input())

N.insert(0,0)
ans=0
for i in range(len(N)-1,-1,-1):
  n=int(N[i])
  if n//10>=1:
    N[i-1]=str(int(N[i-1])+1)
    continue
    
  if n==5:
    if int(N[i-1])>=4:
      N[i-1]=str(int(N[i-1])+1)
    ans+=5
  elif n>=6:
    ans+=10-n
    N[i-1]=str(int(N[i-1])+1)
  else:
    ans+=n
    
print(ans)