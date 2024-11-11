n, x = map(int, input().split())
p, q = [1] + [0] * n, [1] + [0] * n

for i in range(1, n+1):
    p[i] = p[i-1] * 2 + 1
    q[i] = q[i-1] * 2 + 3    

def rec(i, x):
    if i == 0: return 1 if x >= 1 else 0
    mid = q[i] // 2
    if x < mid:
        return rec(i-1, x-1)
    else:
        return p[i-1] + 1 + rec(i-1, x-mid-1)

print(rec(n, x))
