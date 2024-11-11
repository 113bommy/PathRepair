s, w =input(), int(input())
ans = ''
c = 0
while c < len(s)-1:
    ans += s[c]
    c += w
print(ans)