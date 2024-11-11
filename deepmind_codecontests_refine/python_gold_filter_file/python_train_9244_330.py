n = int(input())
r = [int(input()) for _ in range(5)]
m = min(r)
print(-(-n // m) + 4)