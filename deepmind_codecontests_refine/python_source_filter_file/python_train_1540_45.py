a, b = map(int, input().split())
c = sum(map(int, input().split()))

print(max(c - a, -1))