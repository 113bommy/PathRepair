x,y=map(int,input().split())
if abs(x)==abs(y):
  print((x*y<0)+0)
elif x*y==0:
    print(abs(x-y)+(x>0 or y<0)*1)
elif x*y<0:
  print(1+abs(abs(x)-abs(y)))
else:
  print((x<y)*2+abs(abs(x)-abs(y)))
