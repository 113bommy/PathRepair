a = input()
i = 0
ans = 1
c = 0
while i < len(a):
    i += 1
    c = i - 1
    while i < len(a) and a[i]=='0':
        i += 1
    if c > i - c:
        ans += 1
    elif c == i - c:
        if a[:c] > a[c:i]:
            ans += 1
        else:
            ans = 1
    else:
        ans = 1
print(ans)