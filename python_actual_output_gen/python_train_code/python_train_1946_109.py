a, b = map(int, input().split())
print(sum(sorted([a, b, a-1, b-1])[:2]))