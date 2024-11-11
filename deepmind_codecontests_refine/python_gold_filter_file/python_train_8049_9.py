n = int(input())
w = list(map(int, input().split(" ")))
ans = 0
for x in range(n):
    ans += w[x]
for i in range(2, n):
    che = []
    if n % i == 0 and n // i >= 3:
        che = [0]*(i)
        for j in range(n):
            che[j%i] += w[j]
        for j in range(i):
            ans = max(che[j], ans)
print(ans)
