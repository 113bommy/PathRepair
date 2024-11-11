S = input()
T = input()

n = 0
for s,t in zip(S,T):
  if s == t: n += 1

print(n)