n=int(input())
sup=0
sdown=0
flag=0
for i in range(n):
  a=input().split()
  sup+=int(a[0])
  sdown+=int(a[1])
  if not((int(a[0]) % 2)==(int(a[1]) % 2)):
    flag=1
if (sup % 2==0) and (sdown % 2==0):
  print('0')
if not((sup % 2)==(sdown % 2)):
  print('-1')
if (sup % 2==1) and (sdown % 2==1) and flag and (n>1):
  print('1')
if (sup % 2==1) and (sdown % 2==1) and not(flag or (n>1)):
  print('-1')