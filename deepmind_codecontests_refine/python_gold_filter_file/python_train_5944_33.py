n=int(input())
l=list(map(int,input().split()))
s=""
for i in range(n):
  
  if(l[i]%2==0):
    s=s+" "+str(l[i]-1)
  else:
    if(l[i]==n-1):
      s=s+" "+str(l[i]+1)
    else:
      s=s+" "+str(l[i])

print(s)

  