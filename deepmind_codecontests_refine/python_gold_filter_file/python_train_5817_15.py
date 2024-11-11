import re
t = input()
while "B" in t:
    t = t.lstrip("B")
    t = re.sub('[0,1]B','', t)
print(t)
