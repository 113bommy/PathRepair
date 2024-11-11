s = input()
for i in range(4):
  if s[i] != s[i+1]:
    print("Bad")
    exit()
print("Good")