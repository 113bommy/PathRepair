from sys import stdin

# n number of words
# m dictionary
# f first language
# s second language

f = []
s = []
n, m = [int(c) for c in stdin.readline().split()]
for _ in range(0, m):
    x, y = stdin.readline().split()
    f.append(x)
    s.append(y)
# lecture lecture
# w word
# ind index of word
ind = 0
note = ''
lecture = stdin.readline().split()

for w in lecture:
    ind = f.index(w)
    if len(s[ind]) < len(f[ind]):
        note = note + ' ' + s[ind]
    else:
        note = note + ' ' + w
    print(note[1:])
