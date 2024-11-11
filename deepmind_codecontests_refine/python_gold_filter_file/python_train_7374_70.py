n = int(input())
c = 0 
for _ in range(n):
  n,m = map(int,input().split())
  c += m-n+1
print(c)