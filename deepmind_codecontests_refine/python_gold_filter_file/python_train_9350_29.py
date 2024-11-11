n,k = map(int,input().split())
l = list(map(int,input().split()))
ls = []
for i in range(n-k+1):
  a = l[i]
  b = l[i+k-1]
  ls.append(min(abs(a)+abs(a-b), abs(b)+abs(a-b)))
print(min(ls))