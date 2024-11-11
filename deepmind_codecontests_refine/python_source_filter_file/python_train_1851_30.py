N,D = map(int,input().split())
a = 0
for num in range(1,N) :
  X,Y = map(int,input().split())
  if X*X + Y*Y <= D*D :
    a += 1
print(a)