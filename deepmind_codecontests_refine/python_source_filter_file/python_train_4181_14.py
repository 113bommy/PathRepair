n = int(input())
for i in range(n):
    s = list(input())
    t = sorted(s)
    flag = "Yes"
    for j in range(1, len(s)):
        if ord(s[j]) != ord(s[j - 1]) + 1:
            flag = "No"
            break
    print(flag)
