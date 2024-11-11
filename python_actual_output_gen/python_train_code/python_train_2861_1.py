n, k = map(int, input().split())
s = input()
pref = 0
for i in range(1, len(s)):
    if s[:i] == s[len(s) - i:]:
        pref += 1
    #else:
     #   break
print(s, end='')
for i in range(k - 1):
    print(s[pref:], end='')