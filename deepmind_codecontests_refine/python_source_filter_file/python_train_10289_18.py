s = input()

if len(s) > 26:
    a = [0 for _ in range(26)]

    for i in range(len(s)):
        a[ord(s[i]) - ord("a")] += 1

    ans = s
    for i in range(26):
        if a[i] == 0:
            ans += chr(i+ord("a"))
            break

    print(ans)
    exit()


for i in range(24,-1,-1):
    for j in range(25,i,-1):
        if s[i]<s[j]:
            print(s[:i]+s[j])
            exit()

print(-1)