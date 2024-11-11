a = input()

for i in range(3):
  if a[i] == a[i+1]:
    print("Bad")
    return
print("Good")