n = int(input())
a = map(int, input().split())
print(max(a) * n - sum(a))