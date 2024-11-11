N = int(input())
N_d = int(N/2)
X1 = list(map(int,input().split()))
X = X1[:]
X1.sort()

def getMed(i):
  if i  < X[N_d]:
    print(X[N_d])
  else:
    print( X[N_d -1])

for i in X:
  getMed(i)
 