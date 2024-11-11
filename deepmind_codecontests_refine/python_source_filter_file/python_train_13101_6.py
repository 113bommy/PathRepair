n, c, k = map(int, input().split())

t = [0] * n
for i in range(n):
    t[i] = int(input())
t = sorted(t)
ans = 0
i = 0
while i < n:
    j = 0
    while i + j < n and t[i + j] < t[i] + k and j < c:
        j += 1
    i += j
    ans += 1 
print(ans)
