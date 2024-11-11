s=input()
for i in range(len(s)):
    if i>=1:
        if s[i]==s[i-1]:
            print(i-1, i)
            exit()
    if i>=2:
        if s[i]==s[i-2]:
            print(i-2, i)
            exit()
print(-1 -1)