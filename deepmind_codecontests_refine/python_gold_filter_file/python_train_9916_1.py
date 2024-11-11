from sys import stdin, stdout
t = int(input())
answers = []
for _ in range(t):
    s = stdin.readline().strip()

    if len(s)<3: 
        answers.append(0)
    
    elif len(s) == 3:
        if s == '010' or s== '101':
            answers.append(1)
        else:
            answers.append(0)
    else:
        # len > 3
        pref = [0]*(len(s))
        tot = 0
        for i in range(len(s)):
            tot += int(s[i])
            pref[i] = tot

        ans = 10**4
        flip = [False]*(len(s))
    # A string is called good if it does not contain "010" or "101" as a subsequence

        for i in range(1, len(s)):
            a = i - (pref[i-1]) + pref[-1] - pref[i]
            b = pref[i-1] + len(s) - i - 1 - (pref[-1] - pref[i])
            ans = min(ans, a, b)

        answers.append(ans)

print(*answers, sep = '\n')
