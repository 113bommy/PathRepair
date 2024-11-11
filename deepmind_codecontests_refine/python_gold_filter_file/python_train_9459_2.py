n = int(input())
a = [[int(input()),i] for i in range(n)]
a.sort()
ans = 0
for i,tmp in enumerate(a):
  x,j = tmp
  ans += abs(i-j) % 2
print(ans//2)
#print(a)
