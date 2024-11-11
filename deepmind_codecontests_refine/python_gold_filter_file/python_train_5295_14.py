S = list(input())
l = len(S)
l2 = l % 2

if S[0] != S[-1]:
  if l2 == 0:
    winner = "Second"
  else:
    winner = "First"
else:
  if l2 == 0:
    winner = "First"
  else:
    winner = "Second"

print(winner)