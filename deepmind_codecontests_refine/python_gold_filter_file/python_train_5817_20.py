s = input()
ans = ""
for l in s:
    if l == "B":
        ans = ans[:-1]
    else:
        ans += l
print(ans)