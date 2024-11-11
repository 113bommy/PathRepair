s = input()
zerkalo = "AHIOTUVWXY"
for i in s:
    if i not in zerkalo:
        print("NO")
        exit()
for i in range(len(s) // 2):
    if s[i] != s[len(s) - i - 1]:
        print("NO")
        exit()
print("YES")
