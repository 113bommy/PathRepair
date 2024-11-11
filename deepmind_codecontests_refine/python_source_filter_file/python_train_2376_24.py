import sys

H, W, *A = map(int, sys.stdin.read().split())

ans = []
n = 0
ans_append = ans.append
for i in range(H*W-1):
    if i % W == W-1:
        continue
    if A[i] % 2:
        A[i+1] += 1
        n += 1
        ans_append(map(str, (i//W+1, i%W+1, (i+1)//W+1, (i+1)%W+1)))
for i in range(W-1, W*H-1, W):
    if A[i] % 2:
        A[i+W] += 1
        n += 1
        ans_append(map(str, (i//W+1, i%W+1, (i+1)//W+1, (i+1)%W+1)))

print(n)
print('\n'.join(' '.join(row) for row in ans))
