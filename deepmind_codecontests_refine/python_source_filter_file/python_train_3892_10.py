def checkPalindrome(s):
    return s == s[::-1]


s = input()
s = list(s)
freq = [0] * 10**3
flag = 0
total = []
if checkPalindrome(s):
    print("First")
else:
    for i in range(len(s)):
        freq[ord(s[i]) - 97] += 1
    for i in range(len(freq)):
        if freq[i] % 2 != 0:
            if freq[i] == 1 and flag == 0:
                flag = 1
                continue
        total.append(freq[i])
    if flag == 0 and len(total) > 0:
        tsum = sum(total) - 1
    else:
        tsum = sum(total)
    if tsum % 2 == 0:
        print("First")
    else:
        print("Second")
