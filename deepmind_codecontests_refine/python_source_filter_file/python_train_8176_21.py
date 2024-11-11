from collections import Counter
s = input()
counter = Counter(s[:26])
left, right = 0, 0
if len(counter) - int("?" in counter) + counter["?"] == 26:
    left, right = 0, 26
else:
    for i in range(26, len(s)):
        counter[s[i]] += 1
        counter[s[i-26]] -= 1
        if counter[s[i-26]] == 0:
            del counter[s[i-26]]
        if len(counter) - int("?" in counter) + counter["?"] == 26:
            left, right = i - 26, i
            break
if right:
    a = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ") - counter.keys()
    ans = ""
    for i in range(len(s)):
        if s[i] == "?":
            if left <= i < right:
                ans += a.pop()
            else:
                ans += "A"
        else:
            ans += s[i]
    print(ans)
else:
    print("-1")
