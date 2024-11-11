n = int(input())
string = input()

genome = [ x for x in 'ACTG' ]
ans = 10e9

def dist(a, b):
    a = ord(a)
    b = ord(b)
    a, b = min(a, b), max(a, b)
    d1 = b - a
    d2 = (ord('Z') - b) + (a - ord('A')) + 1
    d = min(d1, d2)
    return d

for i in range(n - 3):
    s = 0
    ind = 0
    test = [ x for x in string[i:i+4] ]
    for c in zip(test, genome):
        if c[0] != c[1]:
            s += dist(c[0], c[1])
    if s < ans:
        ans = s

print(s)
