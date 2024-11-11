w = input()

sw = set(w)

for s in sw:
  if w.count(s) != 2:
    print("No")
    exit(0)

print("Yes")

