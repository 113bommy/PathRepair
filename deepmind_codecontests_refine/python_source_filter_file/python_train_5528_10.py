s = input()

n = len(s);prepos = -1

b = ''

for i in range(1, n):
    if s[i] != s[i-1]:
        prepos = i
    else:
        break
    
b = s[:prepos + 1][::-1] + s[prepos+1:][::-1]

cnt = 1; ans1 = 1
    
for i in range(1, len(s)):
    if s[i] != s[i-1]:
        cnt += 1
    else:
        ans1 = max(ans1, cnt)
        cnt = 1

ans1 = max(ans1, cnt)

cnt = 1; ans2 = 1
for i in range(1, len(b)):
    if b[i] != b[i-1]:
        cnt += 1
    else:
        ans2 = max(ans2, cnt)
        cnt = 1

ans2 = max(ans2, cnt)

print(max(ans1, ans2))
