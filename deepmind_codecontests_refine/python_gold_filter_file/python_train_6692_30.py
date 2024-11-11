t=int(input())
while(t>0):
  n=int(input())
  if(n<10):
    div=n-1
    print(div*10+1)
    t-=1
    continue
  elif(n>10 and n<100):
    div=n//11-1
    print(div*10+3)
    t-=1
    continue
  elif(n>100 and n<1000):
    div=n//111-1
    print(div*10+6)
    t-=1
    continue
  elif(n>1000 and n<10000):
    div=n//1111-1
    print(div*10+10)
    t-=1
    continue