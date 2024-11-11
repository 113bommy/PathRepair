n = int(input())
ans = 0
for a in range(1,n+1):
    y = n//a
    ans+=int((y*(y+1)*a)/2)
print(ans)