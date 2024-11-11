t = int(input())
for _ in range(t):
    s = input()
    pred = -1
    res = 0
    if s[0] == 1:
        pred = 0
    for j in range(1, len(s)):
        if s[j] == '1' and pred == j - 1:
            pred = j
        elif s[j] == '1' and pred != -1:
            res += j - pred - 1
            pred = j
        elif s[j] == '1':
            pred = j
    print(res)