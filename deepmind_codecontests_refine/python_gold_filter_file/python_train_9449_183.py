a, b, c, d = map(int, input().split())

n = [a*c, a*d, b*c, b*d]
print(max(n))