n = int(input())
k = list(map(int,input().split()))
r = 0
for i in range(n):
  if k[k[i]-1] == i+1: r += 1
print(r//2)
