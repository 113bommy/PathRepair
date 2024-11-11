import re

r = r"(ogo(go)*)"

s = input()

s = re.sub(r, '***', s)

print(s)
