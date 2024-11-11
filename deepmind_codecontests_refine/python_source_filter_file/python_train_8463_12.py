def readln(): return tuple(map(int, input().split()))

n, m = readln()
p = [input() for _ in range(n)]
while p[0] == '.' * m:
    p = p[1:]
while p[-1] == '.' * m:
    p.pop()
pref = min([_.split('*')[0] for _ in p])
suf = min([_.split('*')[-1] for _ in p])
for _ in p:
    print(_[len(pref):-len(suf)])
