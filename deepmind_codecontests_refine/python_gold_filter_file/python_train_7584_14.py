h = {'a': [], 'b': [], 'c': []}
h['a'] = list(input())
h['b'] = list(input())
h['c'] = list(input())

p = 'a'
while len(h[p]) > 0:
    p = h[p].pop(0)
print(p.upper())