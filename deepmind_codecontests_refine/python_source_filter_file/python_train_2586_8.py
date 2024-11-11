n = int(input())
a=[0]
for i in range(n):
  a.append(int(input()))
c = 1
k = a[1]
while k != 1:
  if k == 2:
    print(c)
    exit()
  k = a[k]
  c += 1
print(-1)  