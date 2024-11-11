# https://codeforces.com/problemset/problem/1368/C

n=int(input())

print(n+n+2+n)

for x in range(n+2):
  print(x,x)
for x in range(n):
  print(x,x+1)
  print(x+1,x)

