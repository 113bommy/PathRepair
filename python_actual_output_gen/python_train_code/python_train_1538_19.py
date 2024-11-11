s = input()

n = len(s)
r = "NO"

for i in range(n):
    for j in range(i, n):
        w = s[:i] + s[j:]
        if w == "CODEFORCES":
            r = "YES"

print(r)