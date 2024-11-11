n = int(input())
a = "<3".join([""] + [input() for _ in range(n)] + [""])
s = input()
i = 0
for c in a:
  i = s.find(c, i)
  if i == -1:
    print("no")
    exit()
print("yes")