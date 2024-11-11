a = list(map(int, input().split()))
print(sum(a) + max(a[:-1]) * 9)