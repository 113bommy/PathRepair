from sys import stdin,stdout
a, b = map(int, input().split())
qw = set()
def hash(st):
    h = 0
    for l, i in enumerate(st):
        h += ord(i) * pow(22231, l, 10**9 + 7)
        h %= (10**9 + 7)
    return h
for i in range(a):
    qw.add(hash(stdin.readline().strip()))
 
for i in range(b):
    er = stdin.readline().strip()
    t = hash(er)
    boo = 0
    for l in range(len(er)):
        xx = pow(22231, l, 10**9 + 7)
        if er[l] != 'a' and (t + xx*(97-ord(er[l]))) % (10**9 + 7) in qw:
            boo = 1
            stdout.write('YES\n')
            break
        if er[l] != 'b' and (t + xx*(98-ord(er[l]))) % (10**9 + 7) in qw:
            boo = 1
            stdout.write('YES\n')
            break
        if er[l] != 'c' and (t + xx*(99-ord(er[l]))) % (10**9 + 7) in qw:
            boo = 1
            stdout.write('YES\n')
            break
    if boo == 0:
        stdout.write('NO\n')
