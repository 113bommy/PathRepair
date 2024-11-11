s = list(input())
l, r = 0, len(s) - 1
ans = 0
while l != r:
    if s[l] == s[r]:
        l += 1
        r -= 1
    else:
        if s[l] == "x":
            l += 1
            ans += 1
        elif s[r] == "x":
            r -= 1
            ans += 1
        else:
            ans = -1
            break

print(ans)
