n = int(input())
arr = list(map(int, input().split()))
x = sum(arr) % n
print(max(x, n - x))