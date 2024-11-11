n = list(input())

m = set(n)

ans = 0
if m != {'1','0'}:
    for i in n:
        ans += int(i)
else:
    ans = 10
print(ans)
