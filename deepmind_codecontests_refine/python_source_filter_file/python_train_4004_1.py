a,b,c = map(int, input().split())

ans = []
for i in range(1, 82):
    n = b* i**a + c
    if n > 0 and sum(map(int, str(n))) ==  i and i < 10**9:
        ans.append(n)

print(str(len(ans)))
print(*ans)