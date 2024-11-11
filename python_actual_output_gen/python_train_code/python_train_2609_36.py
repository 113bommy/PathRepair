n,k = map(int, input().split())
lst = [int(input()) for _ in range(n)]
lst.sort()
print(min(h[i + k - 1] - h[i] for i in range(n - k + 1)))
