n=int(input())

dnum =0
dsum =0

for i in range(n):
  d,c=map(int,input().split())
  dnum += c
  dsum += d*c
  
ans = c-1 + dsum//9

print(ans)