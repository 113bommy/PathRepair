N=int(input())
a = 2
ans = 1
while a * a <= N:
  b = a
  while b <= N:
    ans = max(ans,b)
    b *= a
  a+=1
print(ans)

