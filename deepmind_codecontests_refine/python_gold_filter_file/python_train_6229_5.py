w,b=map(int, input().split())
A,B,C,D=['##'],['..'],['#.'],['.#']
w-=1
b-=1
print(100,50)
for i in range(100):
  if i<50:
    if i%2==1:
      print(*A*25,sep='')
    elif w>=25 and i%2==0:
      print(*C*25,sep='')
      w-=25
    else:
      E=C*w+A*(25-w)
      print(*E,sep='')
      w=0
  else:
    if i%2==0:
      print(*B*25,sep='')
    elif b>=25 and i%2==1:
      print(*D*25,sep='')
      b-=25
    else:
      F=D*b+B*(25-b)
      print(*F,sep='')
      b=0