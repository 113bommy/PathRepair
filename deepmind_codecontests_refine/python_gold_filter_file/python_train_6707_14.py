from collections import Counter
s,w = Counter(input()), Counter('nineteen')
f = lambda k,v: (s['n']-1)//2 if k == 'n' else s[k]//v
print(max(0, min(f(k,v) for k,v in w.items())))