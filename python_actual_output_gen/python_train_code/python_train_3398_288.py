N=input()
R=input()
N=int(N)
R=int(R)
if N<10:
  R+=100*(10-N)
print(R)