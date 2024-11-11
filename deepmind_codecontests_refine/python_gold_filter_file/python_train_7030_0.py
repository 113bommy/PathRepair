# cf 665 C 1200
s = list(input())
# aaa
#  ^
for i in range(1, len(s)):
    if s[i - 1] == s[i]:
        use = set(['x', 'y', 'z'])
        if i - 1 >= 0 and s[i - 1] in use:
            use.remove(s[i - 1])
        if i + 1 < len(s) and s[i + 1] in use:
            use.remove(s[i + 1])
        s[i] = use.pop()
print("".join(s))
