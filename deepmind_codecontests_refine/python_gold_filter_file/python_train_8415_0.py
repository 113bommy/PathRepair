a=int(input())
b=int(input())
if a==b:
  print(1)
  exit()
abin=bin(a)[2:]
bbin=bin(b)[2:]
la=len(abin)
lb=len(bbin)
if la==lb:
  while abin[0]==bbin[0]:
    abin=abin[1:]
    bbin=bbin[1:]
  while len(abin)>1 and abin[0]=="0":
    abin=abin[1:]
cbin=bbin[1:]
while cbin and cbin[0]=="0":
  cbin=cbin[1:]
c=2**(len(cbin))-1
a=int(abin,2)
b=int(bbin,2)
lb=len(bbin)
lbnd=2**(lb-1)+c
hbnd=2**(lb-1)+a
if lbnd>=hbnd:
  print(2**lb-a)
else:
  print(2**(lb-1)-a+lbnd-a+1)
