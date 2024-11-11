a = list(map(int,input().split()))
a.sort()
for i in a:
  if a%2 == 0:
    print(0)
    exit()
print(a[0]*a[1])