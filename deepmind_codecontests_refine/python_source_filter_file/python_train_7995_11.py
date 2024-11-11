n,m = map(int,input().split())
x = list(map(int,input().split()))
x.sort()
y = []
for i in range(1,m):
  y.append(x[i] - x[i-1])
y.sort()
print(sum(y[:m-n]))