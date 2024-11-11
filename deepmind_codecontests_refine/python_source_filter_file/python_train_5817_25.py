import re
t = input()
while "B" in t:
    t = t. lstrip("B")
    t = re.sub('.B','', t)
print(t)