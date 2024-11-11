s = input()
if s[-2] == s[-1]:
    print(len(s)-1, len(s))
    exit()

for i in range(s-2):
    if s[i] == s[i+1] or s[i] == s[i+2]:
        print(i+1, i+3)
        exit()
print(-1 - 1)
