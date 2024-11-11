n = int(input())
a = list(map(int,input().split()))
c = 0
for i in range(n):
  if i == a[a[i]-1]-1:
    c += 1
print(c//2)
