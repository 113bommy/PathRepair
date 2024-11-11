k=int(input())
x=[k%4, max(-0.1,k-7)%4, max(-0.1,k-14)%4, max(-0.1,k-21)%4]
if x.count(0)==0: print("NO")
else:
  y=7*x.index(0)
  seven=x.index(0)
  z=(k-y)//4
  if z>=7: 
    seven+=z//7*4
    z=z%7
  print('4'*z+'7'*seven)