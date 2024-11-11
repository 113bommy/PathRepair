import re
ans = list(map(len, re.findall("[ACGT]+", input())))
print(ans)