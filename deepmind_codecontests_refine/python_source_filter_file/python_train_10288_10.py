import sys
n=int(input())
s=[[int(i) for i in l.split()] for l in sys.stdin]
for cx in range(101):
  for cy in range(101):
    H=[]
    Z=[]
    for i in range(n):
      x,y,h=s[i]
      if h!=0:
        H.append(abs(x-cx)+(y-cy)+h)
      else:
        Z.append(abs(x-cx)+(y-cy))
    if len(Z)==0:
      Z.append(10**18)
    if H.count(H[0])==len(H) and min(Z)>=H[0]:
      print(cx,cy,H[0])
      exit()