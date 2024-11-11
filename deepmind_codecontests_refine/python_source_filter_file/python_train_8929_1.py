n = int(input())
d = {}
for _ in range(n) :
    s = input()
    if s in d :
        d[s] += 1
    else :
        d[s] = 1

mx = max(d.values())
for s in sorted(k for k in d if d[k] == m) :
    print(s)
