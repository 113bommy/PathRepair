s = input()
n = len(s)
for i in range(n - 1):
    if s[i] == s[i + 1]:
        print(i + 1, i + 2)
        exit()
    if i + 2 < n and s[i] == s[i + 2]:
        print(i + 1, i + 3)
        exit()
print(-1)
