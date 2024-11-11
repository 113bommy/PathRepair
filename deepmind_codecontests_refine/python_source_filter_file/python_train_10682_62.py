string = input().split(' ')

n = int(string[0])
k = int(string[1])
t = int(string[2])

if t <= k:
  print(t)
elif t <= n:
  print(str(t - (t-k)))
else:
  print(str(t-n+1))