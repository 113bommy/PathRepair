N, X, Y = list(map(int,input().split()))
X -= 1
Y -= 1
out = [0]*N
for i in range(N-1):
  for j in range(i+1,N):
    out[min(j-i, abs(i-X)+1+abs(j-Y))] += 1
for i in range(N-1):
  print(out[i])