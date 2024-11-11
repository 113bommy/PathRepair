k,t = map(int,input().split())
a = list(map(int,input().split()))
if t == 1:
  print(k-1)
else:
  print(max(0,2*max(a)-k-1))
