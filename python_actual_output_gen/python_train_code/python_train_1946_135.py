a, b = map(int, input().split())

print(max(a+a-1, a+b-1, b+b-1))