n = int(input())
a = [0] * n
b = list(map(int, input().split()))
s = 0
for x in range(1,n):
  s += abs(b[x-1]-b[x])

print(s+1)