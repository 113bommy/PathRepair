a = int(input())

b = list(map(int,input().split()))

b.sort()

su = 0

for i in range(a-1):
  su += b[2*i]
print(su)