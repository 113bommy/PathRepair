s = input()

for i in range(len(s) - 2):
    if (s[i] == s[i + 1] or s[i] == s[i + 2]):
        print("{} {}".format(i + 1, i + 3))
        break
else:
    if (s[-2] == s[-1]):
        print("{} {}".format(len(n) - 1, len(n)))
    else:
        print("-1 -1")

