N, M= map(int, input().split())
sw = [list(map(int, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))

def mask(l):
    m = 0
    for i in l:
        m += 2**(i-1)
    return m

masks = list(map(mask, sw))

ret = 0
for i in range(2**N):
    if all(bin(i&m).count('1')%2 == p for m, p in zip(masks, P)):
        ret += 1
print(ret)
