a, b, c, d = int(map(int, input().split()))
print(max(a*c, max(a*d, max(b*c, b*d))))
