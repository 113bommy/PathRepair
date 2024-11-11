n,k,s=map(int,input().split())
if s==10**9:
  res=(str(s)+'')*k+'1 '*(n-k)
else:
  res=(str(s)+'')*k+(str(s+1)+'')*(n-k)
print(res[:-1])
