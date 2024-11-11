coin = int(input())

ans = "NO"

a = coin // 1234567

for x in range(a, -1, -1):
    b = (coin - (a*1234567)) // 123456

    for y in range(b, -1, -1):
        c = (coin - (a*1234567) - (b*123456)) // 1234

        if a*1234567 + b*123456 + c*1234 == coin:
            ans = "YES"
            break

        if ans == "YES":
            break

    if ans == "YES":
        break

print(ans)