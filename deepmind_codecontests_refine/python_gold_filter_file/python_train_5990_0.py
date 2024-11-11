n, m = map(int, input().split())
t = [[] for i in range(6)]
for i in range(m):
    a, b = input().split()
    t[ord(b) - ord('a')] += [a]

l = ['a']
A = 0
while len(l) > 0:
    L = []
    for s in l:
        if len(s) == n:
            A += 1
            continue
        for i in range(1):
            ch = s[i]
            for new in t[ord(ch) - ord('a')]:
                L += [s[:i] + new + s[i+1:]]
    l = set(L)

print(A)
                
