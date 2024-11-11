a,b,c,k = list(map(input(),split()))
if a+b >= k:
  print(min(a,k))
else:
  print(a-(k-a-b))