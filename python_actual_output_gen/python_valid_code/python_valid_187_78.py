n, a, b = map(int, input().split())
ans = (n//(a+b)) * a + min(b,n%(a+b))
print(ans)