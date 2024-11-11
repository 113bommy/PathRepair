def div_ceil(x, y): return (x + y - 1) // y

N = int(input())
*A, = map(int, input().split())
cand_min, cand_max = 2, 2
for a in reversed(A):
    if div_ceil(cand_min, a) > cand_max: print(-1); break
    cand_min = div_ceil(cand_min, a) * a
    cand_max = (cand_max // a) * a + a - 1
else:
    print(cand_min, cand_max)