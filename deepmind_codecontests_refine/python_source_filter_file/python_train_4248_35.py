N = int(input())
ans = 0
m = 10
if N ^ 1:
    print(0)
    exit()
while N > m:
    ans += N//m
    m *= 5
print(ans)
