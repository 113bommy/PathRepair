import sys,heapq
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True # and False
def ddprint(x):
  if DBG:
    print(x)

n = inn()
vowels = ['a', 'e', 'i', 'o', 'u']
h = {}
for v in vowels:
    h[v] = {}
counts = defaultdict(int)
for i in range(n):
    s = input()
    cnt = 0
    lastvow = '.'
    for j in range(len(s)):
        if s[j] in vowels:
            cnt += 1
            lastvow = s[j]
    #ddprint("s {} cnt {} lastvow {}".format(s,cnt,lastvow))
    if cnt not in h[lastvow]:
        h[lastvow][cnt] = []
    h[lastvow][cnt].append(s)
    counts[cnt] += 1

npairs = 0
for cnt in counts:
    npairs += counts[cnt]//2

nvpairs = 0
for v in vowels:
    for cnt in h[v]:
        nvpairs += len(h[v][cnt])//2

nlyrics = min(npairs//2, nvpairs)
if nlyrics == 0:
    print(0)
    exit()

lyrics = [0] * nlyrics
lcnt = 0
for v in vowels:
        for cnt in h[v]:
            while len(h[v][cnt]) >= 2:
                w21 = h[v][cnt].pop()
                w22 = h[v][cnt].pop()
                lyrics[lcnt] = [w21,w22]
                lcnt += 1
                if lcnt == nlyrics:
                    break
            if lcnt == nlyrics:
                break
        if lcnt == nlyrics:
            break

#ddprint(lyrics)

words = {}
for v in vowels:
    for cnt in h[v]:
        if cnt not in words:
            words[cnt] = []
        words[cnt].extend(h[v][cnt])

lcnt = 0
for cnt in words:
    while len(words[cnt]) >= 2:
        w11 = words[cnt].pop()
        w12 = words[cnt].pop()
        lyrics[lcnt].extend([w11,w12])
        lcnt += 1
        if lcnt == nlyrics:
            break
    if lcnt == nlyrics:
        break

print(nlyrics)
for z in lyrics:
    print("{} {}".format(z[2], z[3]))
    print("{} {}".format(z[0], z[1]))
