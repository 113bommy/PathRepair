# https://codeforces.com/problemset/problem/1368/C

n=int(input())

print(n+1+n+2+n+1)

for x in range(n+2):
  print(x,x)
for x in range(n+1):
  print(x,x+1)
  print(x+1,x)
