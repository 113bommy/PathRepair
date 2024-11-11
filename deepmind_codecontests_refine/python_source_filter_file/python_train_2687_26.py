import re
s=input()
r=[0]
for i in re.finditer("[ACGT]+", s):
    r.append(len(i[0]))
print(max(r))
