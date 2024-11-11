n = int(input())
a = list(map(int,input().split()))
d = {}
for i in a:
  if ((i+n)%2 == 0) and (i != 0):
    print(0)
    exit()
  if i in d:
    d[i] += 1
    if (d[i] == 3) or (i == 0):
      print(0)
      exit()
  else:
    d[i] = 1
ans = 1
for i in list(d.values()):
  ans *= i
print(ans%1000000009)