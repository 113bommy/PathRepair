n,k = map(int, input().split())
lst = [int(input()) for _ in range(n)]
lst.sort()
print(min(lst[i + k - 1] - lst[i] for i in range(n - k + 1)))
