n = int(input())
s = input()

ans = s
ma = 1

for k in range(0, n - 1):
    t = s[k:k + 2]
    cnt = 0
    for i in range(k, n - 1):
        if s[i:i + 2] == t:
            cnt += 1
    if cnt > ma:
        ma = cnt
        ans = t

print(ans)

