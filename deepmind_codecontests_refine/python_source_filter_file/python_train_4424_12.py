s = input()
n = len(s)
ans = "NO"
for i in range(n):
    for j in range(i, n):
        if s[:i] + s[j:] == "CODEFORCES":
            ans = "YES"

print(ans)
        
