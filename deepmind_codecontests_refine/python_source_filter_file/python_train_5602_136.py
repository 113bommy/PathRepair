a,b = map(int, input(),split())
ans = max(a + b, 2*a-1, 2*b-1)
print(ans)