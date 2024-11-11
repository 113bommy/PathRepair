s = input()
s = sorted(list(s), reverse=True)
print(s)
ans = s[0]
for i in range(1,len(s)):
    if ans[-1] == s[i]:
        ans+=s[i]

    else:
        break

print(ans)
