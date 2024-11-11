char = set('Bulbasaur')
d = dict()
for i in char: d[i] = 0

s = input()
for i in s:
    if i in char: d[i] += 1

for i in d:
    if i in ('a','u'): d[i] //= 2

print(min(d[i] for i in d))