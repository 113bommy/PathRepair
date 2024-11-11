a, b = list(map(int, input().split()))

print(min(a, b), print((a - min(a, b))//2 + (b - min(a, b))//2))