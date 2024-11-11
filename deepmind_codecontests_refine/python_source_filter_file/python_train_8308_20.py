N = int(input())
a = [0 for i in range(N)]
chain = [0 for i in range(N)]
for i in range(N):
  a[i] = int(input())
  chain[a[i]] = chain[a[i]-1]+1
print(max(chain))