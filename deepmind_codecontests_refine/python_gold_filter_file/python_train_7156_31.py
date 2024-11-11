s = input()
for i in range(1, len(s) - 1):
    if s[i] == 'A' and ((s[i - 1] == 'B' and s[i + 1] == 'C') or (s[i - 1] == 'C' and s[i + 1] == 'B')):
        print("Yes")
        exit()
    elif s[i] == 'B' and ((s[i - 1] == 'C' and s[i + 1] == 'A') or (s[i - 1] == 'A' and s[i + 1] == 'C')):
        print("Yes")
        exit()
    elif s[i] == 'C' and ((s[i - 1] == 'B' and s[i + 1] == 'A') or (s[i - 1] == 'A' and s[i + 1] == 'B')):
        print("Yes")
        exit()
print("No")
