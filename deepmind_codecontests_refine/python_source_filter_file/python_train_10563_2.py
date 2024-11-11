s = input().split()
n = int(s[0])
m = int(s[1])
mass1 = {}
mass2 = {}
for i in range(m):
    s = input().split()
    mass1[s[0]] = s[1]
    mass2[s[1]] = s[0]
s = input()
res = []
for st in s.split():
    if st in mass1:
        if len(st) < len(mass1[st]):
            res.append(st)
        else:
            res.append(mass1[st])
    else:
        if len(st) < len(mass2[st]):
            res.append(st)
        else:
            res.append(mass2[st])
print(' '.join(res))
