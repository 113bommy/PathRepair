n = int(input())
s = input()
q = ["a", "i", "u", "e", "o"]
t = s
i = 0
while i < len(t) - 1:
    if s[i] in q and s[i + 1] in q:
        t = s[:i + 1] + s[i + 2:]
        s = t
        i = 0
    else:
        i += 1

print(t)