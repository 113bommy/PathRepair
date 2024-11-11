import sys
input = sys.stdin.readline
from collections import Counter
import itertools

mask = (1 << 10) - 1

def encode(a,b,c,d):
    t = 1 << 40
    for x,y,z,w in [(a,b,c,d), (b,c,d,a), (c,d,a,b), (d,a,b,c)]:
        u = x + (y << 10) + (z << 20) + (w << 30)
        if t > u:
            t = u
    return t

def decode(x):
    for _ in range(4):
        yield x & mask
        x >>= 10

def P(n,k):
    x = 1
    for i in range(k):
        x *= (n-i)
    return x

def symmetry(tile):
    a,b,c,d = decode(tile)
    if a == b == c == d:
        return 4
    if a == c and b == d:
        return 2
    return 1

N = int(input())
tiles = []
for _ in range(N):
    a,b,c,d = map(int,input().split())
    tiles.append(encode(a,b,c,d))
counter = Counter(tiles)

counter

answer = 0
for bottom, top in itertools.combinations(tiles,2):
    counter[bottom] -= 1
    counter[top] -= 1
    a,b,c,d = decode(bottom)
    e,f,g,h = decode(top)
    for x,y,z,w in [(e,f,g,h), (f,g,h,e), (g,h,e,f), (h,e,f,g)]:
        # a,b,c,d
        # x,w,z,y 
        tiles = [encode(p,q,r,s) for p,q,r,s in [(b,a,x,w), (c,b,w,z), (d,c,z,y), (a,d,y,x)]]
        need = Counter(tiles)
        x = 1
        for tile, cnt in need.items():
            x *= P(counter[tile],cnt) # 残っている個数、必要枚数
            x *= pow(symmetry(tile), cnt)
        answer += x
    counter[bottom] += 1
    counter[top] += 1

# 上下を固定した分
answer //= 3
print(answer)