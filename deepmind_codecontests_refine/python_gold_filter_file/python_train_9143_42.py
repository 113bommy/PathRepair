a,b,c,d = map(int,input().split())
ans = min(b,d) - max(a,c)
print(max(0,ans))