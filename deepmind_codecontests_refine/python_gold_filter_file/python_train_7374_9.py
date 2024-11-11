N = int(input())
a = 0

for i in range(N):
  l,r = list(map(int,input().split()))
  a+=r-l+1

print(a)
