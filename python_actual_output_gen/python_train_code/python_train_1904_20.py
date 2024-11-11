M = int(input())
S = 0
res = -1
for _ in range(M):
    d, c = map(int, input().split())
    res += d
    S += c

res += S // 9
print(res)