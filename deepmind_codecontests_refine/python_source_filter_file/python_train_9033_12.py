R = lambda: map(int, input().split())
n, k = R()
print(sum(sorted(R())[:n - k]))
