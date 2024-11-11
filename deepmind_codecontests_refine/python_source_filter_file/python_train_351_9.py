n = int(input())

arr = list(map(int, input().split()))

print(min(int((sum(arr) + n - 2) / (n - 1)), max(arr)))