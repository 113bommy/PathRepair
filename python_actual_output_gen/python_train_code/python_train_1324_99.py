a,b,c = map(int,input().split())
ans = b + min(c,a+b+a)
print(ans)