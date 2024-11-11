k,a,b = map(int,input().split())
if b-a <= 2:
  print(k+1)
elif  a+2 > k:
  print(k+1)
else:
  print(a+int((k+1-a)/2)*(b-a)+(k+1-a)%2)