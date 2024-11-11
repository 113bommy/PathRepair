m: int = int(input().split()[1])

d: str = dict([])

for _ in range(m):
    s = input()
    w = s.split()
    if len(w[0]) < len(w[1]):
        d[w[0]] = w[0]
        d[w[1]] = w[0]
    else:
        d[w[0]] = w[1]
        d[w[1]] = w[1]

s = input().split()
print(' '.join([d[w] for w in s]))
