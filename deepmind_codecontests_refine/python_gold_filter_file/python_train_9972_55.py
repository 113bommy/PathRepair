a, b = map(int, input().split())
print(str(a)*b if b >= a else str(b)*a)