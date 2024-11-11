n,a,b = map(int, input().split())
s = list(map(int, input().split()))
k = a*s.count(0)+b*s.count(1)
for i in range((n+1)//2):
    if s[i] != s[-i-1] == 2:
        s[-i-1] = s[i]
    if s[i] == s[-i-1] == 2:
        s[-i-1] = 0 if a < b else 1
    if s[i-1] != s[i] ==2:
        s[i] = s[-i-1]
print(s)
print((a*s.count(0)+b*s.count(1)-k)if s == s[::-1] else -1)