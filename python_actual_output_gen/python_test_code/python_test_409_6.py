x, t, a, b, da, db = map(int, input().split())
la = [0] + list(range(a, a - t * da, -t))
lb = [0] + list(range(b, b - t * db, -t))
print('YES' if any(pa + pb == x for pa in la for pb in lb) else 'NO')