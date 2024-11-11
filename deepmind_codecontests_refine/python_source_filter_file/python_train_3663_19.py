n = int(input())
da = [int(i) for i in input().split()]
data = [(da[i], i + 1) for i in range(n)]

data.sort(reverse=True)
ans2 = [i[1] for i in data]
ans = 0
for i in range(n):
    ans += data[i][0] * (i+1) + 1
print(ans)
print(*ans2)

