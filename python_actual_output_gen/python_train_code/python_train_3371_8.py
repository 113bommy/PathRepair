s = input(),
j = (len(s) // 2) if len(s) % 2 != 0 else (len(s) // 2) - 1
k = j
for i in range(len(s)):
    if i % 2 is 0:
        print(s[k], end='')
        j += 1
    else:
        print(s[j], end='')
        k -= 1
