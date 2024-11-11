n=int(input())
if n>1:
  if n%2==0:
    print((n//2)**2 -1, (n//2)**2 +1)
  else:
    print((n**2-1)//2, (n**2+1)//2)
else:
  print(-1)