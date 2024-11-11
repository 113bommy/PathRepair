a,b,c,d = map(int, input().split())
ans = max(a*d,a*c,b*d,b*c)
print(ans)
