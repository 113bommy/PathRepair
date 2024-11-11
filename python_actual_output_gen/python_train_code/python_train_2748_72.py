s = input()
k = int(input())
for c in range(len(s)):
    if s[c] != "1":
        print(s[c])
        exit()
print(1)