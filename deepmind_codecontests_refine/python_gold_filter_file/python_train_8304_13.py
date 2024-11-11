x, y = map(int, input().split())
a = list(map(int, input().split()))
print("Yes" if sum(a) >= x else "No")