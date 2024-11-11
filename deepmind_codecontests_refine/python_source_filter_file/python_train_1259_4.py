T = int(input().strip())

out = []
for i in range(T):
    n = int(input().strip())
    s = input().strip()
    flag = True
    for i in range(n):
        if s[i] != s[n-1-i] and abs(ord(s[i])-ord(s[n-1-i])) != 2:
            out.append('No')
            flag = False
            break
    if flag:
        out.append('YES')

print('\n'.join(out))