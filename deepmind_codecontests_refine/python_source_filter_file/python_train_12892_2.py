n=int(input())
S1=input()
S2=input()

mod=1000000007
if n==1:
  print(3)
else:
  if S1[0]==S2[0]:
    ans,i=3,1
  else:
    ans,i=6,2
  while i<n:
    if S1[i]==S2[i]:
      ans *= 2%mod if S1[i-1]==S2[i-1] else 1%mod
      i+=1
    else:
      ans *= 2%mod if S1[i-1]==S2[i-1] else 3%mod
      i+=2
print(ans%(mod))