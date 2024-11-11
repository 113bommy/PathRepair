from collections import Counter
s = input()
n = len(s)
ans = True
if n > 2:
    for i in range(n - 2):
        if max(list(Counter(s[i:i+3]).values())) > 1:
            print(i + 1, i + 3)
            ans = False
            exit()
    if ans:
        print(-1, -1)
else:
    if max(list(Counter(s).values())) > 1:
        print(1, 3)
    else:
        print(-1, -1)