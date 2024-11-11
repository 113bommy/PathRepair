s = input()
mo = res = dong = 0
for i in range(len(s)):
    if s[i] == '(':
        mo += 1
    else:
        if mo >= dong:
            dong += 1
            res = max(res, min(mo, dong) * 2)
print(res)