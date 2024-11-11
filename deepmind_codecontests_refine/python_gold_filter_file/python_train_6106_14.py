n = int(input())
ls = list(map(int, input().split()))
s = input()
r = int(1e9)
l = -r
i = 4
while i < n:
    if s[i] == s[i - 1]: 
        i += 1
        continue
    if s[i] == '1': 
        l = max(l, max(ls[i - 4 : i + 1]) + 1)
    elif s[i] == '0':
        r = min(r, min(ls[i - 4 : i + 1]) - 1)
    i += 1
print(l, r)



