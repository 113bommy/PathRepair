s = input()
t = s[len(s)//2]
j = len(s)//2
i = len(s)-j-1
ans = j
while i >= 0:
    if s[i] != t or s[j] != t:
        break
    ans += 1
    i -= 1
    j += 1

print(ans)