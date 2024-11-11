for i in range(1):
  n,m=map(int,input().split())
  if n!=0 and m!=0:
   if abs(n-m)==0 or abs(n-m)==1:
    print('YES')
   else:
    print('NO')
  else:
      print('NO')