def binpow(a, b, c):
    if b >= a:
        return 0
    uk1 = 0
    uk2 = 2000000000
    while uk2 - uk1 > 1:
        if a - ((uk2 + uk1) // 2) * (b + c) <= a :
            uk2 = (uk2 + uk1) // 2
        else:
            uk1 = (uk2 + uk1) // 2

    return uk2

n = int(input())
l = list(map(int, input().split()))
f, x = list(map(int, input().split()))
ans = 0
for i in range(n):
    ans += binpow(l[i], f, x) * x
print(ans)
