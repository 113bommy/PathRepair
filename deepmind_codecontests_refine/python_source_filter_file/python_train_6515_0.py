n = int(input())
a = list(map(int, input().strip().split()))
print(max(a) - a[len(a) - 1])
