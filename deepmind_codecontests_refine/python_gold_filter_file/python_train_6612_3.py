a, b = map(int, input().split())
c, d = map(int, input().split())

print(max(abs(a-c), abs(d-b)))