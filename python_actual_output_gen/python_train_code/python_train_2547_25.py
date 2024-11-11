n = int(input())
p = 0
for i in range(n):
  l, r = map(int, input().split())
  p += r-l+1
 
print(n)
