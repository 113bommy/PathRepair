l = int(input())
s = str(input())
cnt = 0
ans = ""
for i in range(0,len(s),2):
    ans += s[i]
    if s[i] == s[i+1]:
        cnt += 1
        ans += 'b' if s[i-1] is 'a' else 'a'
    else:
        ans += s[i+1]
print(cnt)
print(ans)