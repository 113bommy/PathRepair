n, a, b = tuple(map(int, input().split()))
s = list(map(int, input().split()))
ans = 0
for i in range(len(s) // 2):
    if (s[i] != s[len(s) - i - 1]) and (s[i] + s[len(s) - i - 1] == 1):
        print(-1)
        exit(0)
    elif (s[i] != s[len(s) - i - 1]) and (s[i] + s[len(s) - i - 1] == 2):
        ans += a
    elif (s[i] != s[len(s) - i - 1]) and (s[i] + s[len(s) - i - 1] == 3):
        ans += b
    elif (s[i] + s[len(s) - i - 1] == 4):
        ans += (min(a, b) * 2)
if (s[len(s) // 2] == 2) and (len(s) % 2 != 0):
    ans += min(a, b)
print(ans)