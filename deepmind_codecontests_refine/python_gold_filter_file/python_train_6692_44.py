T=int(input())

def Compute():
  x=input()
  lenx=len(x)
  xfirst=int(x[0])
  N=(xfirst-1)*10
  return N+lenx*(lenx+1)/2

for t in range(1,T+1):
  print(int(Compute()))