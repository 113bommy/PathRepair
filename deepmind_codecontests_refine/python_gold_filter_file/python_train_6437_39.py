s = input()
n = len(s)

t = [n]
for i in range(1, n):
    if s[i] != s[i-1]:
        t.append(max(i, n-i))
print(min(t))