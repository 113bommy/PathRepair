n, k = map(int, input().split())
s = input()
mx = 0

for i in range(n-1):
    if s[:i+1] == s[n-(i+1):]:
        mx = max(mx, i+1)

print(end=s[:n-mx]*k)
print(s[n-mx:])