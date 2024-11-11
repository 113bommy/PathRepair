N = int(input())
aN = [ int(i) for i in input().split() ]
bN = [0] * N

for i in range(N, 0, -1):
    if sum(aN[i-1: :i]) % 2 != aN[i - 1]:
        bN[i-1] = 1

print(sum(bN))
if sum(bN) != 0:
    print(*[i+1 for i, b in enumerate(bN) if b == 1])
