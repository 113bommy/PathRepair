a,b,c,d = map(int, input().split())

ans = max([a*c,b*c,a*d,b*d])

print(ans)