s = input().strip()
max_s = 0
for char in range(len(s) - 2):
    for p in range(char, len(s) - 1):
        s2 = s[p:]
        if s2 != s2[::-1]:
            if len(s2) > max_s:
                max_s = len(s2)
print(max_s)