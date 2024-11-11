a,b,c,d = map(int, input().split())
ans = max(a*c, b*c, b*d)
print(ans)