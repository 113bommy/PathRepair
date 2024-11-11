n, k = map(int, input().split())
h = list(map(int, input().split()))
print(sum(sorted(h)[:-k]))