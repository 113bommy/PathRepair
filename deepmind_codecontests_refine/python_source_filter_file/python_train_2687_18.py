import re
s = input()
m = re.findall(r"([ACGT]+)", s)
print(max(m, key=len) if m else 0)
