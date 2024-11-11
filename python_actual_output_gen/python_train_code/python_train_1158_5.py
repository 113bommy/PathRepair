def ab():
  b,c=map(int,input().split())
  e=c//(b-1)
  e=e*b
  z=c%(b-1)
  if(z==0):
    print(e-1)
  else:
    print(e+1)




for i in range(0,int(input())):
  ab()