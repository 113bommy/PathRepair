M = int(input())
S = -1
res = -1
for _ in range(M):
    d, c = map(int, input().split())
    res += c
    S += d*c

res += S // 9
print(res)