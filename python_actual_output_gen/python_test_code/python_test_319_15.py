n,a,b=map(int,input().split())
if (a-b)%2==0:
  ans=(a-b)//2
else:
  ans=min(a-1,n-b)+1+(b-a-1)//2
print(ans)