n=int(input())
l= list(map(int, input().split()))
b=list(set(l))
m=len(b)
if m!=1:
  
    if m==2:
      if (b[0]%2==0 and b[1]%2==0) or (b[0]%2!=0 and b[1]%2!=0):
        D=abs(b[1]-b[0])//2
      else :
        D=(b[1]-b[0])
        D=abs(D)
    elif m==3:
      if (b[1]-b[0])==(b[-1]-b[-2]):
          D=b[1]-b[0]
          D=abs(D)
      else:
        D=-1
    else:
      D=-1
    print(D)
else:
  print(0)