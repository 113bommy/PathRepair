n = int(input())
ans = n
for i in range(n):
    c = 0
    t = i
    while(t > 0):
        c += t%6
        t //= 6
    t = n-i
    while(t > 0):
        c += t%9
        t //= 9
    if ans > c:
        ans = c
print(ans)