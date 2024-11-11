k,a,b = list(map(int,input().split()))
if (((b-a)/2) <= 1) or (k <= a):
  print(k+1)
else:
  t = k-a+1
  print((t//2)*(b-a)+(t%2)+a)