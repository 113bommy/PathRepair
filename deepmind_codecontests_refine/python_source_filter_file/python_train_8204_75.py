n = int(input())
s = input()
ans = max(len(set(s[:i]) & set(s[i:])) for i in range(1, n - 1))
print(ans)
