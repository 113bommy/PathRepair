from sys import stdin, stdout
def f(t):
    for i in t:
        if i != ' ': return i == '#'
    return False
r, s = [], []
q = None
for t in stdin.readlines():
    if f(t):
        if q != None:
            s.append(q)
            q = None
        s.append(t[: -1])
    elif q == None: q = t.replace(' ', '')[: -1]
    else: q += t.replace(' ', '')[: -1]
if q != None: s.append(q)
stdout.write('\n'.join(s))