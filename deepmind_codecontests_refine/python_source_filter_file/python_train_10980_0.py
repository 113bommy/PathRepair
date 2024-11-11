n = input()
s = input()
s = s.lower()
check = {}
count = 0
for i in range(0, len(s), 2):
    if s[i] != s[i + 1]:
        if s[i] in check:
            check[s[i]] += 1
        else:
            check[s[i]] = 1
        if s[i + 1] not in check:
            count += 1
            continue
        else:
            if check[s[i + 1]] >= 1:
                check[s[i + 1]] -= 1
            if check[s[i]] == 0:
                del check[s[i + 1]]
print(count)
