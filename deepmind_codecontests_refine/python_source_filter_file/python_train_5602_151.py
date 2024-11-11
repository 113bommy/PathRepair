a, b = map(int, input().split())
print(max(a,b) + max(max(a,b), min(a,b)))
