n=int(input())
ans=2*(n//11)
n=n%11
if n==0:
  ans+=0
elif n<=6:
  ans+=1
else:
  ans+=2
print(ans)
