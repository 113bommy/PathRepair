N,T=map(int,input().split())
cc=1000
for i in range(N):
  c,t=map(int,input().split())
  if cc>c and T>=t:
    cc=c
if cc==1000:
  print("TLE")
else:
  print(cc)