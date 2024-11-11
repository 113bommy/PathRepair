N = int(input())
K = int(input())
x = list(map(int,input().split()))
res = 0
for i in x:
  res += 2* min(x,K-x)
print(res)