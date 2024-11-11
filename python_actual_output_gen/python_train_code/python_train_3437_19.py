a, b = map(int, input().split())
if a < b:
    b = a
print(str(b)*a)