a,b,c,d = map(int,input().split())
ans = max(a*c,a*d,b*c,d*b)
print(ans)