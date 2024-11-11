H,W=map(int,input().split())
if H==1 and W==1:
  print(1)
else:
  print(H*W//2+H*W%2)