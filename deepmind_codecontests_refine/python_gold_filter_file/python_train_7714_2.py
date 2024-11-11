l, r=map(int, input().split())
print ('YES')
for i in range(1, (r-l+1)//2+1):
  print (2*i-1+l-1, 2*i+l-1)