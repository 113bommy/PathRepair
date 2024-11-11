s = input()
k = int(input())


ans = []
for c in s[:-1]:
    to_a = ord('z')-ord(c)+1
    if k < to_a:
        ans.append(c)
    else:
        k -= to_a
        ans.append('a')
else:
    c = s[-1]
    x = ord(c)-ord('a')
    y = (k+x) % 26
    ans.append(chr(ord('a')+y))


print(''.join(ans))
