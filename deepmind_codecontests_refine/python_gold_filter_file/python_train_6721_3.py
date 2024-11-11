n = int(input())
s = input()
ans, i = 0, 0
while (i < n) and (s[i] != '>'):
    i += 1
    ans += 1
i = n - 1
while (i >= 0) and (s[i] != '<'):
    i -= 1
    ans += 1
print(ans)