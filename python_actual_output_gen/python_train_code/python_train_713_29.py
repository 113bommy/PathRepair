[n, m, k] = [int(i) for i in input().split()]

if(k<n):print(k+1, 1)
else:
  k-=n
  r = n - (k // (m-1))
  
  if(r%2==0):
    c = 1 + (k % (m-1))
  else:
    c = m - (k % (m-1))
  print(r, c)