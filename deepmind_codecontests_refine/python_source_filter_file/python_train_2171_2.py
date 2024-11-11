a,b,c = map(int,input().split())
ans = 0
if a == b == c and a%2 == 0:
    print(-1,-1,-1)
    exit()
while a%2 == b%2 == c%2 == 0:
    x,y,z = a//2, b//2, c//2
    a = y + z
    b = x + z
    c = x + y
    ans += 1
print(ans)