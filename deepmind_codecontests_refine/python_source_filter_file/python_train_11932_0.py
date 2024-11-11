from random import seed, sample
from functools import lru_cache

req_left = 1999

@lru_cache(None)
def ask(x):
    global req_left
    req_left -= 1
    print("?", x, flush=True)
    return tuple(map(int, input().split()))

seed(1337)

n, start, x = map(int, input().split())

ch = sample(range(1, n+1), n // 50 + 1)
if start not in ch:
    ch.append(start)

mv = 0
mc = 1

for c in ch:
    v, n = ask(c)
    if v < x:
        if v > mv:
            mv = v
            mc = c
    if v == x:
        print("!", v, flush=True)
        exit(0)

#print("probing done")

nxt = mc
while req_left > 0:
    if nxt == -1:
        break
    #print(nxt)
    v, nxt = ask(nxt)
    #print("aa")
    if v >= x:
        print("!", v, flush=True)
        exit(0)
    

print("!", -1)

    
    
    


