n = int(input())
s = [input() for u in range(n)]
a = sum([u.count("AB") for u in s])
b = len([1 for u in s if u.endswith("A")])
c = len([1 for u in s if u.startswith("B")])
d = len([1 for u in s if u.endswith("A") and u.startswith("B")])
if (b==c and c==d):
  print(a+b-1)
else:
  print(a+min(b,c))