n,m = map(int,input().split())
X = sorted(map(int,input().split()))
D = []

for i in range(m-1):
  D.append(X[i+1]-X[i])

print(sum(sorted(D)[:len(D)-n+1]))