a,b = map(int,input().split())
c = input()
cl  = list(c)

if a==1 and b==1:
  print('0')
elif b==0:
  print(a)
else:  

  if cl[0]!='1':
    cl[0]='1'
    b-=1
  for i in range(1,len(cl),1):
    if b<=0:
      break 
    if c[i]!='0':
      cl[i] ='0'
      b-=1
  print(''.join(cl))   

