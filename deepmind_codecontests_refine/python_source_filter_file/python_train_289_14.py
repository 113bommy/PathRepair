S = input()
key = "keyence"
for i in range(len(key)+1):
  if key == S[:i] + S[len(S)-len(key)+i:]:
    print("Yes")
    break
else:
  print("No")
