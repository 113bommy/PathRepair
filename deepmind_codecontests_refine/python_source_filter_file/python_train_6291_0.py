n = int(input())
ans = float('inf')

for i in range(n):
    line = list(map(int, input().split()))
    tm = sum(line) * 5 + (len(line)) * 15
    ans = min(ans, tm)
print(ans)
