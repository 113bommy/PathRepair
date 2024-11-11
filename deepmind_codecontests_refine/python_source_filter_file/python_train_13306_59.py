# D - All Your Paths are Different Lengths

L = int(input())
r = 0
while pow(2, r+1) < L:
    r += 1

N = r + 1 

edge = []
for i in range(N-1): 
    edge.append((i+1, i+2, 0))
    edge.append((i+1, i+2, pow(2, i)))

M = r * 2
remain = L - pow(2, r)

for i in range(N-1)[::-1]:
    if remain < pow(2, i):
        continue
    else:
        edge.append((i+1, N, L-remain))
        M += 1
        remain -= pow(2, i)

print(N, M)
for e in edge:
    print(' '.join(map(str, e)))