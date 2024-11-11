for _ in range(int(input())):
  #n,k=map(int,input().split())
  n=int(input())
  if n<30:
    print('NO')
  else:
    if n-30 in [6,10,14]:
      print('YES')
      print('6 ''10 ','15 ',n-31)
    else :
      print('YES')
      print('6 ''10 ','14 ',n-30)