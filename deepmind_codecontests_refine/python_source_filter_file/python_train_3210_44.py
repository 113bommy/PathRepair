a, b, k = map(int, input().split())
arr = list(range(a, b+1))
for i in sorted(set(arr[:k]) | set(arr[-k:])):
    print(i)