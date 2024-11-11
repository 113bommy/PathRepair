def inpl(): return list(map(int, input().split()))
K, T = inpl()
a = inpl()
print(max(max(a)*2-n-1, 0))