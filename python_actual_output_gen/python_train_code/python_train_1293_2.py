w=input()
for ch in w:
  if w.count(w)%2!=0:
    print("No")
    exit()
print("Yes")