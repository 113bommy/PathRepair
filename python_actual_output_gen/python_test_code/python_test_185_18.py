N = int(input())

S = input()

l = 0
r = 0
for s in S:
  if s == "(":
    r += 1
  else:
    if l:
      r -= 1
    else:
      l += 1
print("("*l + S + ")"*r)
