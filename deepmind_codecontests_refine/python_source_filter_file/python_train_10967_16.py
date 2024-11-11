n, k = map(int, input().split())
s = list(map(int, input().split()))
c = 0
x = 0
for i in range(1, len(s), 2):
    if (k == x) | (i == len(s)-1):
        break
    if (s[i] == s[i-1]+1) & (s[i] == s[i+1]+1):
        continue
    s[i] -= 1
    x += 1
for i in s:
    print(i ,end=' ')