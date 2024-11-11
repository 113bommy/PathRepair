s = input()
k = int(input())
n = len(s)
ans, ind = "", False
count = 0
for i in range(n):
    if s[i] != "?" and s[i] != "*":
        count += 1
if count == k:
    for i in range(n):
        if s[i] != "?" and s[i] != "*":
            ans += s[i]
    print(ans)
elif count > k:
    ans = []
    for i in range(n):
        if s[i] != "?" and s[i] != "*":
            ans.append(s[i])
        elif (s[i] == "?" or s[i] == "*"):
            count1 = 0
            for j in range(i + 1, n):
                if s[j] != "?" and s[j] != "*":
                    count1 += 1
            if len(ans) + count1 > k:
                ans.pop()
    if len(ans) == k:
        res = ""
        for i in ans:
            res += i
        print(res)
    else:
        print("Impossible")
elif count < k:
    ans = []
    for i in range(n):
        if s[i] != "?" and s[i] != "*":
            ans.append(s[i])
        elif s[i] == "*" and not ind:
            ind = True
            for j in range(k - count):
                ans.append(s[i - 1])
    res = ""
    if len(ans) == k:
        for i in ans:
            res += i
        print(res)
    else:
        print("Impossible")

