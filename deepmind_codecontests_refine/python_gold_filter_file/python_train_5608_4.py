a,b,c=map(int,input().split())
if a%2 and b%2 and c%2:
  ans=min([a*b,a*c,b*c])
else:
  ans=0
print(ans)