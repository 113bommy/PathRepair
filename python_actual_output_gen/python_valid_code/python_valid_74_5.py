n=int(input())
ans=""
while n!=0:
  if (n%2)!=0:
    n-=1
    ans="1"+ans
  else:
    ans="1"+ans
  n/=-2
if ans=="":
  ans="0"
print(ans)