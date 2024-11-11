n = int(input())
a = tuple(map(int, input().split()))
print(max(a) * n - sum(a))