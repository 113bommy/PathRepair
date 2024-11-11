a,b,n = map(int,input().split())
i = max(b-1,n)
ans = a*i//b - a*(i//b)
print(ans)