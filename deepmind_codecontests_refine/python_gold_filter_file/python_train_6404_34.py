n = input()

m = input()

ans = ""

for x in range(len(n)):
    if n[x] == m[x]:
        ans += "0"

    else:
        ans += "1"

print(ans)