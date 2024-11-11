s = input()
t = input()
counter = 0
idx = -1
if set(t) <= set(s):
  for i in range(len(t)):
    idx = s.find(t[i],idx+1)
    if idx == -1:
      counter += 1
      idx = s.find(t[i],idx+1)
  print(counter * len(s) +idx +1)
else:
  print(-1)