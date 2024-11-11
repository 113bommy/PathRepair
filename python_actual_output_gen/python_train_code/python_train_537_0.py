s = input()
ans = 1
for i in range(1, 7):
    if s[i] == 1:
        ans += 10
        i += 1
    else:
        ans += int(s[i])
print(ans)