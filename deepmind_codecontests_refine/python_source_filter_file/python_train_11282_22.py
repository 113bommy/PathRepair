# import os


s = input()
t = input()

p = 0

while t:
    if s[p] == t[0]:
        p += 1
    t = t[1:]
print(p)

# 03/01 - 1
# 04/01 - 21
# 05/01 - 27
# 06/01 - 28