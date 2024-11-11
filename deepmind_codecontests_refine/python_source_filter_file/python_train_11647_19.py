s = input()
for i in range(1,len(s)):
    if s[i] == s[i-1]:
        print(i-1, i)
        exit()

for i in range(2,len(s)):
    if s[i]==s[i-2]:
        print(i-2, i)
        exit()

print("-1 -1")
