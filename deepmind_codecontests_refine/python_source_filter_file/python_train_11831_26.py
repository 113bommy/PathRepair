s = input()
ans = 0
for i in range(len(s)):
    if s[i] in ["a","e", "i", "o", "u"]:
        ans += 1
    else:
        if s[i].isdigit() and int(s[i]) % 2 == 0:
            ans += 1

print(ans)