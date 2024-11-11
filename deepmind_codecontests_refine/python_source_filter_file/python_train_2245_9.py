import sys

n, k = map(int, sys.stdin.readline().split())
line = sys.stdin.readline()

idx_g = line.index('G')
idx_t = line.index('T')

idx_max = max(idx_g, idx_t)
idx_min = min(idx_g, idx_t)

if (idx_max - idx_min) % k != 0:
    print("NO")
    sys.exit()

for idx in range(idx_min + k, idx_max - k + 1):
    if line[idx] != '.':
        print("NO")
        sys.exit()

print("YES")
sys.exit()