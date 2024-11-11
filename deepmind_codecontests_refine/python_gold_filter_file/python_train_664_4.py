n = int(input())
a = "<3".join([""] + [input() for _ in range(n)] + [""])
s = input()
i = -1
for c in a:
  i = s.find(c, i + 1)
  if i == -1:
    print("no")
    exit()
print("yes")