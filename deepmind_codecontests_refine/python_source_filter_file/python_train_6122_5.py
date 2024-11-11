n = int(input())
s = list(map(int,input().split()))

ans = 0

for c in range(1,n-1):
  if (n-1)%c == 0:
    p = ((n-1)//c-1)//2 
  else:
    p = (n-1)//c-2
    if p <= 0:
      break
  if p <= 0:
    continue
  m = 0
  k = 0
  for i in range(1,p+1):
    k += s[c*i] + s[n-1-c*i]
    m = max(m,k)
  ans = max(ans,m)
    
    
print(ans)