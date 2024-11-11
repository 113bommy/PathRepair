a, b = map(int, input().split())
c, d = map(int, input().split())

print(min(abs(a-c), abs(d-b)))