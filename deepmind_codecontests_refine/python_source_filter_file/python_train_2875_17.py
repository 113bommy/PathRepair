n, k = map(int,input().split())
worst = 1 if n != k else 0
best = min(n-k, 2*k)
print(worst, best)