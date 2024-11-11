import sys

n, k = map(int, input().split())
mvals = []

for _ in range(n):
    x, y, z, w = map(int, input().split('.'))
    mvals.append((x << 24) | (y << 16) | (z << 8) | w)

mv = (1 << 32) - 1
for ind in range(31,-1,-1):
    st = set()
    mask = mv - ((1 << ind) - 1)
    for i in range(n):
        st.add(mask & mvals[i])
    if len(st) == k:
        x, y, z, w = (mask >> 24), (mask >> 16) % 256, (mask >> 8) % 256, mask % 256
        print(f"{str(x)}.{str(y)}.{str(z)}.{str(w)}")
        exit()

print(-1)



