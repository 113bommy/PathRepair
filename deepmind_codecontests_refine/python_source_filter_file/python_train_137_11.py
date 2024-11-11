from collections import Counter

n = int(input())
s = input()
sc = Counter(s)
r = ''
f = False

for l, v in sc.items():
    if v%n == 0:
        r += l * (v//n)
    else:
        r = -1
        f = True
        break

print(r*2 if not f else r)
