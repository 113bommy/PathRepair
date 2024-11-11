S = input()
ans = ""
for i in S:
    if i == "B":
        ans = ans[0:-1]
    else:
        ans += i
print(ans)