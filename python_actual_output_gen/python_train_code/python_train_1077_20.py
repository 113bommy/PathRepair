N = int(input())
W = map(int,input().split())
t = []
for i in range(1,N):
  t.append(abs(sum(W[:i])-sum(W[i:])))
print(min(t))