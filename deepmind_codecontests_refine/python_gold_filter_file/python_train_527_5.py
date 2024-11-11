temp = input()
n, max_weights = temp.split(" ")
n, max_weights = int(n), int(max_weights)

weights = input()
weights = ''.join(sorted(weights))

prev = 'A'
total = 0
res = 0
result = []
ok = False
for w in weights:
  if ord(w)-1 == ord(prev) or total >= max_weights or (w in result):
    pass
  else:
    prev = w
    total += 1
    result.append(w)
    res += ord(w) - 96
    ok = True
    #print(w)
#print(result)
#print(res)

if (len(result) != max_weights):
  print(-1)
else:
  print(res)