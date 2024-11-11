s, t = input(), input()
mn = 1000
for i in range(len(s)-len(t)):
    curr = 0
    for j in range(len(t)):
        curr += t[j] != s[i+j]
    mn = min(mn, curr)
print(mn)

