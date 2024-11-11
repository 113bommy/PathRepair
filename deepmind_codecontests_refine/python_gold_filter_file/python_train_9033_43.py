n, k = map(int, input().split())
li = sorted(list(map(int, input().split())))
print(sum(li[:(max(n-k, 0))]))
