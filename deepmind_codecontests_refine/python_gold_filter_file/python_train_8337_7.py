n, m = map(int, input().split())
s = input()
t = n - 1
while (t > 0):
    if (s[:t] == s[n-t:]):
        break
    t -= 1
print(s + s[t:] * (m-1))
