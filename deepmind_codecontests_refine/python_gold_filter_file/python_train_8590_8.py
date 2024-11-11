n,d,h=map(int,input().split())
if((n>2 and d==1)or 2*h<d):exit(print(-1))
for i in range(h):print(i+1,i+2)
if(d!=h):
  print(1,h+2)
  for i in range(d-h-1):print(i+h+2,i+h+3)
for i in range(n-d-1):print(1+(d==h),i+d+2)