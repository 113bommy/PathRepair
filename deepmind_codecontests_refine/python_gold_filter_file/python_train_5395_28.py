n = int(input())
ans = [105,165,195,135,189]
ret = 0
for a in ans:
    if a <= n:
        ret += 1
print(ret)