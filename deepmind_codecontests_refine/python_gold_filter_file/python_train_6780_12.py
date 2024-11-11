s = input()
k = int(input())
l = 0
sn = 0
for i in s:
    if i == "?":
        l +=1
    elif i == "*":
        sn += 1
n = len(s)
if n - sn - l > k:
    if sn + l < n - sn - l - k:

        print("Impossible")
    else:
        ned = n - sn - l - k
        ans = ""
        for i in s:

            if ned != 0:

                if i == "?":
                    ned -= 1
                    ans = ans[:-1]
                elif i == "*":
                    ned -= 1
                    ans = ans[:-1]

            if i != "?" and i != "*":
                ans += i
        print(ans)
elif n - sn - l == k:
    ans = ""
    for i in  s:
        if i != "?" and i != "*":
            ans += i
    print(ans)
else:
    if sn == 0:
        print("Impossible")
    else:
        ned = k - (n - sn - l)
        ans = ""
        for i in s:
            if ned != 0 and i == "*":
                ans += ans[-1] * (ned)
                ned = 0
            if i != "?" and i != "*":
                ans += i
        print(ans)
