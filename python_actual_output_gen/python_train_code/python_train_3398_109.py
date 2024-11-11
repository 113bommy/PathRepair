n,r = map(int,input().split())
ans = n
if n < 10:
    ans = r + 100*(10-n)
print(ans)