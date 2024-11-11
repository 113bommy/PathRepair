hands = input()
ans = 0
for i, h in enumerate(hands):
  if i % 2 == 1:
    if h == "p":
      ans -= 1
  else:
    if h == "g":
      ans += 1
      
print(ans)
   