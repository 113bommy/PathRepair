n = int(input())
s = input()
if n == 1:
    print(0)
else:
    alph = "abcdefghijklmnopqrstuvwxyz"
    while True:
        if len(s) == 1:
            break
        mx = 'a'
        index = -1
        for i in range(1, len(s) - 1):
            if s[i] > mx and alph[alph.find(s[i]) - 1] == s[i - 1] or alph[alph.find(s[i]) - 1] == s[i + 1]:
                mx = max(mx, s[i])
                index = i
        if s[0] > mx and alph[alph.find(s[0]) - 1] == s[1]:
            index = 0
            mx = s[0]
        if s[-1] > mx and alph[alph.find(s[-1]) - 1] == s[-2]:
            index = len(s) - 1
            mx = alph[alph.find(s[-1]) - 1]
        if index == -1:
            break
        else:
            s = s[:index] + s[index + 1:]
    print(n - len(s))

