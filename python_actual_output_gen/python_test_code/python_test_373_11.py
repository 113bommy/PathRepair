def sub(a, b):
    s = 0
    for x in b:
        if x in a[s:]:
            s = a.index(x) + 1
        else:
            return False
    return True


s = input()
t = input()

m = 0
for i in range(len(s)):
    for j in range(len(s)):
        if i <= j:
            new_s = s[:i] + s[j + 1:]
            if sub(new_s, t):
                m = max(- i + j + 1, m)
print(m)