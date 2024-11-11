N,R = map(int,input().split())
if N>=R:
  print(R)
else:
  print(R+100*(10-N))