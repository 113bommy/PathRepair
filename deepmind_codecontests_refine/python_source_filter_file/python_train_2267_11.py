X,N = map(int,input().split())

if N == 0:
  print(X)
  exit();

p = [int(i) for i in input().split()]
  
q = set(range(101)) - set(p)  
  
r = sorted(q,key=lambda x:abs(x-X))

print(r[0])