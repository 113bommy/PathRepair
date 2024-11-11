n = int(input())
for l in range(1, 4*10**2):
  if l*(l-1)//2 == n:
    print("Yes")
    print(l)
    S = [[] for _ in range(l)]
    now = 0
    count = 1
    for j in range(l-1):
      for k in range(l-1-j):
        S[now].append(count)
        S[now+1+k].append(count)
        count += 1
      now += 1
    for s in S:
      print(l-1, *s)
    break
else:
  print("No")