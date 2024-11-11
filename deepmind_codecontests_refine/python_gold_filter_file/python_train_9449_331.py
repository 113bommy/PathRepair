a,b,c,d = map(int, input().split())
ans = [a*c, b*c, b*d, a*d]
print(max(ans))