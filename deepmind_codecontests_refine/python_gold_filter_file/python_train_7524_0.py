from collections import Counter
s = input()
p = input()
n = len(s)
k = len(p)
q = {'a': 0, 'b': 0, 'c': 0, 'd': 0, 'e': 0, 'f': 0, 'g': 0, 'h': 0, 'i': 0, 'j': 0, 'k': 0, 'l': 0, 'm': 0, 'n': 0,
     'o': 0, 'p': 0, 'q': 0, 'r': 0, 's': 0, 't': 0, 'u': 0, 'v': 0, 'w': 0, 'x': 0, 'y': 0, 'z': 0, '?': 0}
r = 0
if k > n:
    print(0)
else:
    m = 0
    possible = True
    d = Counter(p)
    for i in range(k):
        q[s[i]] += 1
    for key in d.keys():
        if q[key] > d[key]:
            possible = False
        else:
            m += d[key] - q[key]
    if possible and m == q['?']:
        r += 1
    for i in range(k, n):
        q[s[i - k]] -= 1
        q[s[i]] += 1
        m = 0
        possible = True
        for key in d.keys():
            if q[key] > d[key]:
                possible = False
            else:
                m += d[key] - q[key]
        if possible and m == q['?']:
            r += 1
    print(r)
