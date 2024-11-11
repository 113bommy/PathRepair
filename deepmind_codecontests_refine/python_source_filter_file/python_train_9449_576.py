a, b, c, d = map(int, input().split())
ans = [a*b, a*c, b*c, b*d]
print(max(ans))
