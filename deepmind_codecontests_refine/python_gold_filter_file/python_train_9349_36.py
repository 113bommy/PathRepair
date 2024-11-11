k,a,b = map(int,input().split())
dif = b-a
if dif<=2:
  print(k+1)
else:
  ans = a
  k -= (a-1)
  ans += dif*(k//2)
  ans += (k%2==1)
  print(ans)
