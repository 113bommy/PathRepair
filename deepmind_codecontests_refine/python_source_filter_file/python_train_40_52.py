a,b = map(int,input().split())
ans = a
while a>b:
    ans += a//b
    rem = a%b
    a = a//b
    a += rem
print(ans)