s = "012 345 678 036 147 258 048 246"
a = [input().split() for i in range(3)]
b = a[0] + a[1] + a[2]

for i in [input()for i in range(int(input()))]:
  if i in b:
    s = s.replace(str(b.index(i)), "")
print("Yes" if "  " in s else "No")